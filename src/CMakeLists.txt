set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DGLMARK_DATA_PATH="/data/storage/el2/base/files/")
add_definitions(-DGLMARK_VERSION="2023.01")
add_definitions(-DGLMARK2_EXECUTABLE="ohos")
add_definitions(-DGLMARK2_USE_EGL=1)
add_definitions(-DGLMARK2_USE_GL=1)
add_definitions(-DGLMARK2_USE_OHOS=1)
add_definitions(-DOHOS=1)

find_package(Threads REQUIRED)

include_directories(libpng)
add_subdirectory(libpng)

include_directories(libjpeg-turbo)
add_subdirectory(libjpeg-turbo)

add_subdirectory(zlib)

include_directories(scene-ideas)
include_directories(scene-terrain)

set(GLMARK2_SOURCES
    benchmark-collection.cpp
    benchmark.cpp
    canvas-generic.cpp
    gl-headers.cpp
    gl-visual-config.cpp
    image-reader.cpp
    libmatrix/log.cc
    libmatrix/mat.cc
    libmatrix/program.cc
    libmatrix/shader-source.cc
    libmatrix/util.cc
    main-loop.cpp
    mesh.cpp
    model.cpp
    options.cpp
    results-file.cpp
    scene-buffer.cpp
    scene-build.cpp
    scene-bump.cpp
    scene-clear.cpp
    scene-conditionals.cpp
    scene.cpp
    scene-default-options.cpp
    scene-desktop.cpp
    scene-effect-2d.cpp
    scene-function.cpp
    scene-grid.cpp
    scene-ideas/a.cc
    scene-ideas.cpp
    scene-ideas/d.cc
    scene-ideas/e.cc
    scene-ideas/i.cc
    scene-ideas/lamp.cc
    scene-ideas/logo.cc
    scene-ideas/m.cc
    scene-ideas/n.cc
    scene-ideas/o.cc
    scene-ideas/s.cc
    scene-ideas/splines.cc
    scene-ideas/table.cc
    scene-ideas/t.cc
    scene-jellyfish.cpp
    scene-loop.cpp
    scene-pulsar.cpp
    scene-refract.cpp
    scene-shading.cpp
    scene-shadow.cpp
    scene-terrain/base-renderer.cpp
    scene-terrain/blur-renderer.cpp
    scene-terrain/copy-renderer.cpp
    scene-terrain.cpp
    scene-terrain/luminance-renderer.cpp
    scene-terrain/normal-from-height-renderer.cpp
    scene-terrain/overlay-renderer.cpp
    scene-terrain/renderer-chain.cpp
    scene-terrain/simplex-noise-renderer.cpp
    scene-terrain/terrain-renderer.cpp
    scene-terrain/texture-renderer.cpp
    scene-texture.cpp
    shared-library.cpp
    text-renderer.cpp
    texture.cpp

    glad/src/egl.c
    gl-state-egl.cpp

    native-state-ohos.cpp

    main.cpp
)

# Build GL library with GLAD
add_library(gl_gl STATIC glad/src/gl.c)
target_include_directories(gl_gl PUBLIC glad/include)

add_library(glmark2-drm STATIC ${GLMARK2_SOURCES})
target_include_directories(glmark2-drm PUBLIC libmatrix)
target_link_libraries(glmark2-drm
    gl_gl
    Threads::Threads
    libpng
    jpeg-turbo-local
)
