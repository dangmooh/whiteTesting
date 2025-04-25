#include <gtest/gtest.h>

extern "C" {
    #include "calc.h"
}

TEST(CalcTest, AddTest) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
}

TEST(CalcTest, SubtractTest) {
    EXPECT_EQ(subtract(10, 5), 5);
    EXPECT_EQ(subtract(0, 3), -3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
