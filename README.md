# Basic Orthanc Plugin

The Basic Orthanc Plugin is small project with all the necessary classes and headers to start your Orthanc plugin.

---

This repository was designed based on the [Wado Plugin Tutorial](https://www.codeproject.com/Articles/797118/Implementing-a-WADO-Server-using-Orthanc) and its [Source Code](https://www.codeproject.com/KB/webservices/797118/WadoPluginSources.zip).

## Usage

- Initialize and register your plugin using the method `OrthancPluginInitialize` in `EntryPoint.cpp` file
- Name the plugin using the method `OrthancPluginGetName` in `EntryPoint.cpp` file
- Declare the version using the method `OrthancPluginGetVersion` in `EntryPoint.cpp` file

## Basic Example

The repository has a Basic Plugin already registered, named and versioned. Its files are `BasicPlugin.h` and `BasicPlugin.cpp`. Use it to test the plugin by changing the `BasicPlugin` method in the `BasicPlugin.cpp`. 

The easiest test is performed by changing the `OrthancContext::GetInstance().LogWarning("Processing a Basic Plugin request");` method and issuing a request for the Basic Plugin. The Basic Plugin URL is defined by the command `OrthancContext::GetInstance().Register("/basicPlugin", BasicPlugin);` on `EntryPoint.cpp`. For example:

    http://localhost:8042/basicPlugin
