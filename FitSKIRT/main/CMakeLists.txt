# //////////////////////////////////////////////////////////////////
# ///     The SKIRT project -- advanced radiative transfer       ///
# ///       © Astronomical Observatory, Ghent University         ///
# //////////////////////////////////////////////////////////////////

# ------------------------------------------------------------------
# Builds the FitSKIRT executable
# ------------------------------------------------------------------

# set the target name
set(TARGET fitskirt)

# list the source files in this directory
file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.hpp")

# create the executable target
add_executable(${TARGET} ${SOURCES} ${HEADERS})

# enable multi-threading
find_package(Threads REQUIRED)
target_link_libraries(${TARGET} Threads::Threads)

# add SMILE library dependencies
target_link_libraries(${TARGET} serialize schema fundamentals build)
include_directories(../../SMILE/serialize ../../SMILE/schema ../../SMILE/fundamentals ../../SMILE/build)

# add SKIRT library dependencies
target_link_libraries(${TARGET} skirtcore)
include_directories(../../SKIRT/core ../../SKIRT/mpi ../../SKIRT/utils)

# add FitSKIRT library dependencies
target_link_libraries(${TARGET} fitskirtcore)
include_directories(../core)

# adjust C++ compiler flags to our needs
include("../../SMILE/build/CompilerFlags.cmake")
