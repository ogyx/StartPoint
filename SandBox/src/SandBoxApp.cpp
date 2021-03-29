#include <DotEngine.h>


class ExampleLayer : public DotEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}
	
	void OnUpdate() override
	{
		DOT_INFO("ExampleLayer::Update");
	}

	void OnEvent(DotEngine::Event& event) override
	{
		DOT_TRACE("{0}", event);
	}

private:

};


class SandBox : public DotEngine::Application
{
public:
	SandBox() 
	{
		PushLayer(new ExampleLayer());
		PushOverLayer(new DotEngine::ImGuiLayer());
	}

	~SandBox() 
	{

	}

};

DotEngine::Application* DotEngine::CreateApplication()
{
	return new SandBox();
}

