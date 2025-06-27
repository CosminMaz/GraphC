workspace "GraphC"
    configurations { "Debug", "Release" }
    language "C"
    location "build"

project "GraphC"
    kind "ConsoleApp"
    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin/obj/%{cfg.buildcfg}"
    files { "src/**.c", "src/**.h" }

    filter "system:linux"
        includedirs { "/usr/local/include/SDL3" }
        libdirs { "/usr/local/lib" }
        links { "SDL3", "m" }

    filter "configurations:Debug"
        symbols "On"

    filter "configurations:Release"
        optimize "On"
