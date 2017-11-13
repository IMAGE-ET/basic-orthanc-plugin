#include "OrthancCPlugin.h"
#include "OrthancContext.h"
#include "BasicPlugin.h"

extern "C"
{
	ORTHANC_PLUGINS_API int32_t OrthancPluginInitialize(OrthancPluginContext* context)
	{
		OrthancContext::GetInstance().Initialize(context);
		OrthancContext::GetInstance().LogWarning("Initianting Basic Plugin");
		OrthancContext::GetInstance().Register("/basicPlugin", BasicPlugin);
		return 0;
	}

	ORTHANC_PLUGINS_API void OrthancPluginFinalize()
	{
		OrthancContext::GetInstance().LogWarning("Finalizing Basic Plugin");
		OrthancContext::GetInstance().Finalize();
	}

	ORTHANC_PLUGINS_API const char* OrthancPluginGetName()
	{
		return "basic-plugin";
	}

	ORTHANC_PLUGINS_API const char* OrthancPluginGetVersion()
	{
		return "0.0.1";
	}
}