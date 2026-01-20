#include "strutils.h"
#include <gtest/gtest.h>
#include <vector>

TEST(StringUtilsTest, Slice) {
    EXPECT_EQ(Slice("abcdef", 1, 4), "bcd");
    EXPECT_EQ(Slice("abcdef", -3),    "def");
    EXPECT_EQ(Slice("abcdef", 2),     "cdef");
    EXPECT_EQ(Slice("abc", 5, 6),     "");
    EXPECT_EQ(Slice("", 0, 0),        "");
}

TEST(StringUtilsTest, Capitalize) {
    EXPECT_EQ(Capitalize("hello"),     "Hello");
    EXPECT_EQ(Capitalize("HELLO"),     "Hello");
    EXPECT_EQ(Capitalize("hELLo"),     "Hello");
    EXPECT_EQ(Capitalize(""),          "");
    EXPECT_EQ(Capitalize("a"),         "A");
}

TEST(StringUtilsTest, Upper) {
    EXPECT_EQ(Upper("hello"),          "HELLO");
    EXPECT_EQ(Upper("HeLlO"),          "HELLO");
    EXPECT_EQ(Upper(""),               "");
}

TEST(StringUtilsTest, Lower) {
    EXPECT_EQ(Lower("HELLO"),          "hello");
    EXPECT_EQ(Lower("HeLlO"),          "hello");
    EXPECT_EQ(Lower(""),               "");
}

TEST(StringUtilsTest, LStrip) {
    EXPECT_EQ(LStrip("   abc"),        "abc");
    EXPECT_EQ(LStrip("abc"),           "abc");
    EXPECT_EQ(LStrip("   "),           "");
    EXPECT_EQ(LStrip(""),              "");
}

TEST(StringUtilsTest, RStrip) {
    EXPECT_EQ(RStrip("abc   "),        "abc");
    EXPECT_EQ(RStrip("abc"),           "abc");
    EXPECT_EQ(RStrip("   "),           "");
    EXPECT_EQ(RStrip(""),              "");
}

TEST(StringUtilsTest, Strip) {
    EXPECT_EQ(Strip("  abc  "),        "abc");
    EXPECT_EQ(Strip("abc"),            "abc");
    EXPECT_EQ(Strip("    "),           "");
    EXPECT_EQ(Strip(""),               "");
}

TEST(StringUtilsTest, Center) {
    EXPECT_EQ(Center("ab", 6),         "  ab  ");
    EXPECT_EQ(Center("ab", 5),         " ab  ");
    EXPECT_EQ(Center("abc", 3),        "abc");
    EXPECT_EQ(Center("", 4),           "    ");
    EXPECT_EQ(Center("x", 5, '*'),     "**x**");
}

TEST(StringUtilsTest, LJust) {
    EXPECT_EQ(LJust("ab", 5),          "ab   ");
    EXPECT_EQ(LJust("ab", 2),          "ab");
    EXPECT_EQ(LJust("", 3),            "   ");
    EXPECT_EQ(LJust("x", 5, '*'),      "x****");
}

TEST(StringUtilsTest, RJust) {
    EXPECT_EQ(RJust("ab", 5),          "   ab");
    EXPECT_EQ(RJust("ab", 2),          "ab");
    EXPECT_EQ(RJust("", 3),            "   ");
    EXPECT_EQ(RJust("x", 5, '*'),      "****x");
}

TEST(StringUtilsTest, Replace) {
    EXPECT_EQ(Replace("aaabbbccc", "a", "x"), "xxxbbbccc");
    EXPECT_EQ(Replace("hello world", "o", "0"), "hell0 w0rld");
    EXPECT_EQ(Replace("aaa", "aa", "b"),  "ba");   // overlapping
    EXPECT_EQ(Replace("abc", "", "x"),    "abc");  // empty old
    EXPECT_EQ(Replace("", "a", "b"),      "");
}

TEST(StringUtilsTest, Split) {
    EXPECT_EQ(Split("a b  c"),           std::vector<std::string>({"a","b","c"}));
    EXPECT_EQ(Split("a,b,c", ","),       std::vector<std::string>({"a","b","c"}));
    EXPECT_EQ(Split("abc", ""),          std::vector<std::string>({"a","b","c"}));
    EXPECT_EQ(Split("", ""),             std::vector<std::string>({""}));
    EXPECT_EQ(Split("  "),               std::vector<std::string>({}));
}

TEST(StringUtilsTest, Join) {
    EXPECT_EQ(Join("-", std::vector<std::string>{"a","b","c"}), "a-b-c");
    EXPECT_EQ(Join("",  std::vector<std::string>{"a","b"}),      "ab");
    EXPECT_EQ(Join("x", std::vector<std::string>{}),             "");
}

TEST(StringUtilsTest, ExpandTabs) {
    EXPECT_EQ(ExpandTabs("\t", 4),       "    ");
    EXPECT_EQ(ExpandTabs("a\tb", 4),     "a   b");
    EXPECT_EQ(ExpandTabs("abc\t", 4),    "abc ");
    EXPECT_EQ(ExpandTabs("abc\tdef", 8), "abc     def");
    EXPECT_EQ(ExpandTabs("no-tabs"),     "no-tabs");
}

TEST(StringUtilsTest, EditDistance) {
    EXPECT_EQ(EditDistance("kitten", "sitting"), 3);
    EXPECT_EQ(EditDistance("saturday", "sunday"), 3);
    EXPECT_EQ(EditDistance("abc", "ABC", true), 0);   // ignore case
    EXPECT_EQ(EditDistance("abc", "ABC", false), 3);  // case matters
    EXPECT_EQ(EditDistance("", "abc"), 3);
    EXPECT_EQ(EditDistance("abc", ""), 3);
    EXPECT_EQ(EditDistance("", ""), 0);
}











