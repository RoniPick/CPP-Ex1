/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Roni Pick>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
    /* Add more test here */

    CHECK(nospaces(mat(9, 7, '$', '-')) == nospaces("$$$$$$$$$\n"
													 "$-------$\n"
													 "$-$$$$$-$\n"
													 "$-$---$-$\n"
													 "$-$$$$$-$\n"
													 "$-------$\n"
													 "$$$$$$$$$"));

    CHECK(nospaces(mat(5, 5, '*', '+')) == nospaces("*****\n"
													 "*+++*\n"
													 "*+*+*\n"
													 "*+++*\n"
													 "*****"));

    CHECK(nospaces(mat(3, 3, '#', '~')) == nospaces("###\n"
													 "#~#\n"
													 "###"));

    CHECK(nospaces(mat(1, 1, '$', '-')) == nospaces("$"));
                                                                     
	
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    /* Add more test here */

	// the following tests will fail because there are even numbers
    CHECK_THROWS(mat(8, 5, '#', '!'));
    CHECK_THROWS(mat(10, 2, '#', '!'));

	// the following tests will fail because one of the int inputs is zero
    CHECK_THROWS(mat(0, 3, '*', '-'));
    CHECK_THROWS(mat(1, 0, '*', '-'));
    CHECK_THROWS(mat(0, 0, '*', '-'));

	// the following tests will fail because they are even numbers and zero
    CHECK_THROWS(mat(0, 6, '#', '!'));
    CHECK_THROWS(mat(12, 0, '#', '!'));

	// the following tests will fail because there are negative numbers 
    CHECK_THROWS(mat(-3, 2, '&', '^'));
    CHECK_THROWS(mat(2, -7, '&', '^'));
    CHECK_THROWS(mat(-3, -2, '&', '^'));

}


/* Add more test cases here */

TEST_CASE("Bad input printing") {
	//it will fail because the second char is + instead of the given char ~
    CHECK_THROWS(nospaces(mat(5, 5, '*', '~')) == nospaces("*****\n"
														 "*+++*\n"
														 "*+*+*\n"
														 "*+++*\n"
														 "*****"));

	//it will fail because the first char is ! instead of the given char *
    CHECK_THROWS(nospaces(mat(5, 5, '*', '+')) == nospaces("!!!!!\n"
														 "!+++!\n"
														 "!+!+!\n"
														 "!+++!\n"
														 "!!!!!"));

	//it will fail because it's the second char instead of the first
	CHECK_THROWS(nospaces(mat(1, 1, '$', '-')) == nospaces("-"));

	//it will fail because in the 3rd raw there is a wrong char ~
	CHECK_THROWS(nospaces(mat(5, 5, '*', '+')) == nospaces("*****\n"
														 "*+++*\n"
														 "*+~+*\n"
														 "*+++*\n"
														 "*****"));

	//it will fail because the number of raws is 3 but the given number was 5
	CHECK_THROWS(nospaces(mat(5, 5, '*', '~')) != nospaces("*****\n"
														 "*+++*\n"
														 "*****"));

	//it will fail because the number of chars in each column is 5 but the given number was 3
	CHECK(nospaces(mat(3, 5, '*', '+')) == nospaces("*****\n"
													 "*+++*\n"
													 "*+*+*\n"
													 "*+++*\n"
													 "*****"));
}