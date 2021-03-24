#pragma once
#ifdef DE_PLATFORM_WINDOWS

extern DotEngine::Application* DotEngine::CreateApplication();

int main(int argc, char** argv)
{

    DotEngine::Log::InitLog();
    DOTENGINE_CORE_WARN("TestClient:");
    DOTENGINE_CLIENT_INFO("TestCore:");
	auto app = DotEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif // #ifdef DE_PLATFORM_WINDOWS