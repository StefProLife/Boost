cmake_minimum_required(VERSION 3.5)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(bayan_project VERSION ${PROJECT_VESRION})

find_package(Boost COMPONENTS program_options unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
message("${Boost_INCLUDE_DIRS}")

add_executable(bayan main.cpp)

set_target_properties(bayan PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(bayan
	${Boost_LIBRARIES}
)

target_include_directories(bayan
    PRIVATE "${CMAKE_BINARY_DIR}"
)

install(TARGETS bayan RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT yuri.andreev@mail.com)
set(CPACK_PACKAGE_VENDOR "Andreev@Company")
set(CPACK_PACKAGE_NAME "bayan")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")
include(CPack)