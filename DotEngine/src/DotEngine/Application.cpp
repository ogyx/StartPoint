#include "dotpch.h"
#include "Application.h"

#include "DotEngine/Events/ApplicationEvent.h"
#include "DotEngine/Log.h"

namespace DotEngine
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
        WindowResizeEvent e(1280, 720);
        if(e.IsInCategory(EventCategoryApplication))
            DOT_TRACE(e);
		while (true)
		{

		}
	}
}