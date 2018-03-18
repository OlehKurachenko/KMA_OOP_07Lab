#include <iostream>
#include <string>
#include <cassert>

#include "String.h"

int main() {
	std::cout << "Running unittest for class String..." << std::endl;

	String s_empty;

	char c_str_ptr[] = "KMA 2018";
	String s_c_string(c_str_ptr);

	String s_char('b');

	std::string b("234");
	String s_string(b);

	String s_copy(s_c_string);

	assert(s_copy == s_c_string);

	String s_multcopy(s_c_string, 5);

	s_copy = s_string;

	assert(s_copy == s_string);

	std::string b2("google.com.ua love cats");

	s_multcopy = b2;

	//assert(s_multcopy == static_cast<String>(b2));
	assert(s_multcopy == b2);

	s_copy = c_str_ptr;

	assert(s_copy == c_str_ptr);

	s_copy = 'h';

	assert(s_copy == 'h');

	s_copy = b2;
	std::string b2_copy(s_copy);
	assert(b2 == b2_copy);

	s_copy = c_str_ptr;
	char *const c_str = s_copy.c_string();
	assert(strcmp(c_str_ptr, c_str) == 0);

	assert(s_copy.length() == strlen(c_str_ptr));
	assert(!s_copy.empty());

	s_copy.clear();

	assert(s_copy.empty());

	s_copy = s_c_string;

	assert(s_copy == s_c_string);
	assert(!(s_copy != s_c_string));

	assert(s_c_string <= s_copy);
	assert(s_c_string >= s_copy);

	--s_c_string[s_c_string.length() - 1];

	assert(s_c_string < s_copy);
	assert(s_c_string <= s_copy);
	assert(!(s_c_string > s_copy));
	assert(!(s_c_string >= s_copy));

	s_c_string = "abcd";
	s_copy = "abcd0";

	assert(s_c_string < s_copy);
	assert(s_c_string <= s_copy);
	assert(!(s_c_string > s_copy));
	assert(!(s_c_string >= s_copy));

	s_copy = String(s_c_string, 2);
	s_c_string += s_c_string;

	assert(s_copy == s_c_string);

	char b3_c[] = "global_core";
	std::string b3(b3_c);

	s_copy += b3_c;
	s_c_string += b3;

	assert(s_copy == s_c_string);

	assert(String("Oleh") + ' ' + "Kurachenko" == std::string("Oleh Kurachenko"));

	return 0;
}