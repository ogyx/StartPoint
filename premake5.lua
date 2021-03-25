workspace "DotEngine" -- solution
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist" -- retail mode!! distribution
    }

outputdir = "%{cfg.buldcfg}-%{cfg.system}-%{cfg.architecture}"

project "DotEngine"
    location "DotEngine"
    kind "SharedLib" -- DLL
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "dotpch.h"
    pchsource "DotEngine/src/dotpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "DE_PLATFORM_WINDOWS",
            "DE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "DOT_DEBUG"
        symbols "On"

    filter "configurations:Debug"
        defines "DOT_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "DOT_DIST"
        optimize "On"

project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
    
        includedirs
        {
            "DotEngine/vendor/spdlog/include",
            "DotEngine/src"
        }

        links
        {
            "DotEngine"
        }

        filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "DE_PLATFORM_WINDOWS",
        }

        filter "configurations:Debug"
            defines "DOT_DEBUG"
            symbols "On"

        filter "configurations:Debug"
            defines "DOT_RELEASE"
            optimize "On"
        
        filter "configurations:Dist"
            defines "DOT_DIST"
            optimize "On"
