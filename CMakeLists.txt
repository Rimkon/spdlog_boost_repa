
cmake_minimum_required ( VERSION 3.5 )

               project ( my_flesson VERSION 0.0.1$ENV{TRAVIS_BUILD_NUMBER} )

          find_package (  spdlog  REQUIRED )
          find_package ( Threads  REQUIRED )
          find_package (   Boost  COMPONENTS unit_test_framework REQUIRED )


        configure_file ( version.h.in     ${PROJECT_SOURCE_DIR}/version.h )
    
           add_library ( hello_lib    lib.cpp )
        add_executable ( hello_cli   main.cpp )
        add_executable ( hello_test  test.cpp )

 set_target_properties ( hello_cli
                         hello_lib
                         hello_test
                         PROPERTIES
                         CXX_STANDARD 17
                         CXX_STANDARD_REQUIRED ON
                         COMPILE_OPTIONS "-Wall;-Wpedantic;-Wextra"     
                        )

 set_target_properties ( hello_test
                         PROPERTIES
                         COMPILE_DEFINITIONS   BOOST_TEST_DYN_LYNK
                         INCLUDE_DIRECTORIES   ${Boost_INCLUDE_DIR}
                       )

 target_link_libraries ( hello_cli
                         hello_lib
                         Threads::Threads
                       )

 target_link_libraries ( hello_test                       
                         ${Boost_LIBRARIES}
                         hello_lib
                       )
                       
               install ( TARGETS  hello_cli
                         RUNTIME DESTINATION  bin )               
                     
set ( CPACK_GENERATOR DEB )                     

set ( CPACK_PACKAGE_VERSION_MAJOR   "${PROJECT_VERSION_MAJOR}" )
set ( CPACK_PACKAGE_VERSION_MINOR   "${PROJECT_VERSION_MINOR}" )
set ( CPACK_PACKAGE_VERSION_PATCH   "${PROJECT_VERSION_PATCH}" )

set ( CPACK_PACKAGE_CONTACT  rassant@gmail.com )

set ( CPACK_DEBIAN_PACKAGE_SHLIBDEPS  ON )

include ( CPack )

enable_testing ( )

add_test ( tests_HELLO_WORLD   hello_test )
