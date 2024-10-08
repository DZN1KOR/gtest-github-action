#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(string_calculator_add_when_passed_a_single_number,returns_0_for_empty_string){
 //Arrange
  StringCalculator calculator;
  string input="";
  int expectedsum=0;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}


TEST(string_calculator_add_when_passed_a_single_number,returns_0_for_empty_Zero){
 //Arrange
  StringCalculator calculator;
 
  string input="0";
  int expectedsum=0;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_add_when_passed_a_single_number,returns_1_for_empty_one){
 //Arrange
  StringCalculator calculator;
 
  string input="1";
  int expectedsum=1;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_add_when_passed_two_comma_delimited_numbers,returns_their_sum){
 //Arrange
  StringCalculator calculator;
 
  string input="1,2";
  int expectedsum=3;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_add_when_passed_multiple_comma_delimited_numbers,returns_their_sum){
 //Arrange
  StringCalculator calculator;
 
  string input="1,2,3";
  int expectedsum=6;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_add_when_delimited_with_newline_and_comma,returns_the_sum_based_on_that_delimiter){
 //Arrange
  StringCalculator calculator;
 
  string input="//;\n1;2";
  int expectedsum=3;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_add_when_passed_negative_numbers,throws_an_exception_listing_invalid_values){
  StringCalculator calculator;
  string input="1,-2,-4,5";
  ASSERT_THROW(calculator.Add(input),invalid_argument); 
 }

TEST(string_calculator_when_add_when_passed_numbers_over_1000,ignores_them){
 //Arrange
  StringCalculator calculator;
 
  string input="42,1001,3";
  int expectedsum=45;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}

TEST(string_calculator_when_passed_multicharacter_delimiter,uses_that_delimiter_to_sum_values){
 //Arrange
  StringCalculator calculator;
 
  string input="//[***]\n8***2***3";
  int expectedsum=13;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
TEST(string_calculator_when_passed_multiple_delimiters,sums_on_each_delimiter){
 //Arrange
  StringCalculator calculator;
 
  string input="//[*][%]\n4*2%3";
  int expectedsum=9;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}
TEST(string_calculator_when_passed_multiple_multicharacter_delimiters,sums_on_each_delimiter){
 //Arrange
  StringCalculator calculator;
 
  string input="//[**][%^]\n4**1%^9";
  int expectedsum=14;
  //Act
  int actualSum=calculator.Add(input);
  //Assert
  ASSERT_EQ(actualSum,expectedsum);
}




