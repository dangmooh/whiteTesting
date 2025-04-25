cmake_minimum_required(VERSION 3.10)
project(CProjectWithGTest C CXX)

# 기본 C 표준 설정
set(CMAKE_C_STANDARD 99)

# Google Test 추가
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# 라이브러리 생성 (C 코드)
add_library(calc src/calc.c)

# 테스트 바이너리 생성
enable_testing()

add_executable(test_calc tests/test_calc.cpp)
target_link_libraries(test_calc gtest_main calc)

# 테스트 등록
include(GoogleTest)
gtest_discover_tests(test_calc)
