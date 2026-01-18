#include "strutils.h"
#include <gtest/gtest.h>

//Slice Tests
TEST(SliceTest, Basic){
  EXPECT_EQ(Slice("abcdef", 2, 0), "cdef");
}

//CapitalizeTests
TEST(Capitalize, Basic){
  EXPECT_EQ(Capitalize("abc"), "Abc");
}

//Upper-LowerTests
TEST(UpperTest, Basic){
  EXPECT_EQ(Upper("abc"), "ABC");
}
TEST(SliceTest, Basic){
  EXPECT_EQ(Lower("ABC"), "abc");
}

//Strip Tests
TEST(LStripTest, Basic){
  EXPECT_EQ(LStrip("   abc   "), "abc   ");
}
TEST(RStripTest, Basic){
  EXPECT_EQ(RStrip("   abc   "), "   abc");
}
TEST(StripTest, Basic){
  EXPECT_EQ(Strip("   abc   "), "abc");
}

//JustTests
TEST(CenterTest, Basic){
  EXPECT_EQ(CenterTest("abc", 5, '-'), "-abc-");
}
TEST(LJustTest, Basic){
  EXPECT_EQ(LJust("abc", 5, '-'), "abc--");
}
TEST(RJustTest, Basic){
  EXPECT_EQ(RJust("abc", 5, '-'), "--abc");
}

//ReplaceTests
TEST(ReplaceTest, Basic){
  EXPECT_EQ(Replace("one two one", "one", "1"), "1 two 1");
}

//SplitTests
TEST(SplitTest, Basic){
  std::vector<std::string> expected = {"", "a", "b", ""};
  EXPECT_EQ(Split(",a,b,"), expected);
}

//JoinTests
TEST(JoinTest, Basic) {
    std::vector<std::string> v = {"one", "two", "three"};
    EXPECT_EQ(Join(" | ", v), "one | two | three");
}

//Expand-TabsTest
TEST(ExpandTabsTest, Basic) {
    EXPECT_EQ(ExpandTabs("a\t\tb"), "a       b");
}

//Edit-DistanceTest
TEST(EditDistanceTest, Basic) {
    EXPECT_EQ(EditDistance("skibidi", "toilet"), 5);
}













