// Copyright 2018 Kamelina Julia

#include <gtest/gtest.h>
#include <string.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

#include "include/huffman.h"

using std::make_pair;
using std::pair;

TEST(Huffman_Tests, Can_Encode) {
  //  Arrange
  char* text = const_cast<char*>("AAAAAAABBBBBBBCCDDDCCDDDCCFFFFF");
  vector<pair<char, const char*> > exp = {
    make_pair('A', "01"), make_pair('B', "10"),
    make_pair('C', "111"), make_pair('D', "00"),
    make_pair('F', "110")};

  bool flag = true;
  Huffman huff(text);

  //  Act
  map<char, char*> enc = huff.Encode();
  int i = 0;
  for (auto it = enc.begin(); it != enc.end(); it++, i++) {
    if ((it->first != exp[i].first) || strcmp(it->second, exp[i].second) != 0) {
      std::cout << it->first << " " << it->second << std::endl;
      std::cout << exp[i].first << " " << exp[i].second << std::endl;
      flag = false;
    }
  }

  //  Assert
  EXPECT_TRUE(flag);
}

TEST(Huffman_Tests, Can_Encode2) {
  //  Arrange
  char* text = const_cast<char*>("AAAAAABBBBBBBCCDDDCCDDDCCAA");
  vector<pair<char, const char*> > exp = {
    make_pair('A', "11"), make_pair('B', "10"),
    make_pair('C', "00"), make_pair('D', "01")};
  bool flag = true;
  Huffman huff(text);

  //  Act
  map<char, char*> encoded = huff.Encode();
  int i = 0;
  for (auto it = encoded.begin(); it != encoded.end(); it++, i++) {
    if ((it->first != exp[i].first) || strcmp(it->second, exp[i].second) != 0) {
      flag = false;
    }
  }

  //  Assert
  EXPECT_TRUE(flag);
}

TEST(Huffman_Tests, Throws_When_Create_Nullptr) {
  //  Arrange
  char* text = 0;

  //  Assert
  EXPECT_ANY_THROW(Huffman huff(text););
}

TEST(Huffman_Tests, Throws_When_Encode_Nullptr) {
  //  Arrange
  Huffman huff;

  //  Assert
  EXPECT_ANY_THROW(huff.Encode());
}

TEST(Huffman_Tests, Can_Encode_One_Letter) {
  //  Arrange
  char* text = const_cast<char*>("AAAAAA");
  Huffman huff(text);

  //  Act
  map<char, char*> encoded = huff.Encode();

  //  Assert
  EXPECT_EQ(encoded.size(), 1);
  EXPECT_EQ(encoded.begin()->first, 'A');
  EXPECT_EQ(strcmp(encoded.begin()->second, "1"), 0);
}

TEST(Huffman_Tests, Fano_Conditional) {
  //  Arrange
  char* text = const_cast<char*>("AAAAAAABBBBBBBCCDDDCCDDDCCFFFFF");
  bool flag = true;
  Huffman huff(text);

  //  Act
  map<char, char*> encoded = huff.Encode();
  int size = encoded.size();
  for (auto it = encoded.begin(); it != encoded.end(); it++) {
    auto it2 = it;
    for (int i = 1; i < size - 1; i++) {
      char* to_copy;
      char* to_compare;
      int len;
      it2++;

      if (it2 == encoded.end()) {
        break;
      }

      if (strlen(it->second) > strlen(it2->second)) {
        len = strlen(it2->second);
        to_copy = it->second;
        to_compare = it2->second;
      } else {
        len = strlen(it->second);
        to_copy = it2->second;
        to_compare = it->second;
      }
      char* expr = new char[len];
      snprintf(expr, len, "%s", to_copy);
      expr[len] = '\0';
      if (strcmp(to_compare, expr) == 0) {
        flag = false;
        break;
      }
    }
  }

  //  Assert
  EXPECT_TRUE(flag);
}
