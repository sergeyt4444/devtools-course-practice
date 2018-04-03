// Copyright 2018 Churakov Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Churakov_Sergey_ComplexNumberTest, Can_Divide_By_One) {
    ComplexNumber z(5.5, 10.5);
    ComplexNumber one(1.0, 0);
    EXPECT_EQ(z, z / one);
}

TEST(Churakov_Sergey_ComplexNumberTest, Can_Mult_By_One) {
    ComplexNumber z(5.5, 10.5);
    ComplexNumber one(1.0, 0);
    EXPECT_EQ(z, z * one);
}

TEST(Churakov_Sergey_ComplexNumberTest, Can_Add_Zero) {
    ComplexNumber z(5.5, 10.5);
    ComplexNumber zero(0, 0);
    EXPECT_EQ(z, z + zero);
}

TEST(Churakov_Sergey_ComplexNumberTest, Can_Substract_Zero) {
    ComplexNumber z(5.5, 10.5);
    ComplexNumber zero(0, 0);
    EXPECT_EQ(z, z - zero);
}

TEST(Churakov_Sergey_ComplexNumberTest, Can_Mult_By_Zero) {
    ComplexNumber z(5.5, 10.5);
    ComplexNumber zero(0, 0);
    EXPECT_EQ(z*zero, zero);
}
