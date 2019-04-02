
set(test_source_files ${CMAKE_CURRENT_SOURCE_DIR}/testsMain.cpp
	                  ${CMAKE_CURRENT_SOURCE_DIR}/testsHandle.cpp)

add_executable(Tests ${test_source_files})
target_include_directories(Tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(Tests PRIVATE ${CMAKE_SOURCE_DIR}/extern/catch)
target_link_libraries(Tests Catch2::Catch binOctree)
