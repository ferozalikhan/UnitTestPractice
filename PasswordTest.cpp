/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

// Test for a password with all the same characters
TEST(PasswordTest, all_same_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("BBBBBB");
	ASSERT_EQ(6, actual);
}

// Test for a password with all mixed characters
TEST(PasswordTest, mixed_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaBBcc");
	ASSERT_EQ(2, actual);
}

// Test for a password with mixed case
TEST(PasswordTest, mixed_case)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aBcDeF");
	ASSERT_EQ(1, actual);
}

// Test for a password with mixed case
TEST(PasswordTest, mixed_case2)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aBcDeFg");
	ASSERT_EQ(1, actual);
}

// Test for a password with mixed case
TEST(PasswordTest, mixed_case3)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aBcDeFgH");
	ASSERT_EQ(1, actual);
}

//********************************************************************************

// Now onto testing the has_mixed_case function
// Test case 1: password with all lowercase
TEST(PasswordTest, all_lowercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("abcdef");
	// assert_flase, check if the function returns false and the password has no mixed case
	ASSERT_FALSE(actual);
}

// Test case 2: password with all uppercase
TEST(PasswordTest, all_uppercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ABCDEF");
	// assert_flase, check if the function returns false and the password has no mixed case
	ASSERT_FALSE(actual);
}

// Test case 3: password with mixed case
TEST(PasswordTest, mixed_case_true)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aBcDeF");
	// assert_true, check if the function returns true and the password has mixed case
	ASSERT_TRUE(actual);
}

// Test case 4: password with empty string
TEST(PasswordTest, empty_string)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	// assert_flase, check if the function returns false and the password has no mixed case
	ASSERT_FALSE(actual);
}

// Test case 5: password with all numbers
TEST(PasswordTest, all_numbers)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("123456");
	// assert_flase, check if the function returns false and the password has no mixed case
	ASSERT_FALSE(actual);
}

