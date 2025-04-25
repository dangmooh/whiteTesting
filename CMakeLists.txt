cmake_minimum_required(VERSION 3.10)
project(WhiteBoxCProject C CXX)

set(CMAKE_C_STANDARD 99)

# 🔧 런타임 옵션 /MDd로 통일
foreach(flag_var
    CMAKE_C_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_C_FLAGS_RELEASE
    CMAKE_CXX_FLAGS_RELEASE)
  string(REPLACE "/MT" "/MD" ${flag_var} "${${flag_var}}")
endforeach()

# ✅ GoogleTest 설정 (동적 CRT 강제)
include(FetchContent)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # 핵심
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

include_directories(src)

# 라이브러리 + 테스트 타겟 생성
add_library(calc src/calc.c)
add_executable(test_calc tests/test_calc.cpp)
target_link_libraries(test_calc gtest_main calc)

# 테스트 자동 등록
enable_testing()
include(GoogleTest)
gtest_discover_tests(test_calc)
