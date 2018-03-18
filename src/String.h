//
//  Created by Oleh Kurachenko
//         aka soll_nevermind aka okurache
//  on 2018-03-18T21:02:30Z as a part of KMA_OOP_07Lab
//  
//  ask me      oleh.kurachenko@gmail.com , I'm ready to help
//  GitHub      https://github.com/OlehKurachenko
//  rate & CV   http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//  
#ifndef KMA_OOP_07LAB_STRING_H
#define KMA_OOP_07LAB_STRING_H

#include <cstring>
#include <string>
#include <iostream>

class String {
public:
	class BadString;

	class BadIndex;

	inline String();

	inline String(const char *);

	inline String(const char);

	inline String(const std::string &);

	inline String(const String &str, const size_t multiplayer = 1);

	inline ~String();

	inline String &operator=(const String &);

	inline String &operator=(const std::string &);

	inline String &operator=(const char *);

	inline String &operator=(const char);

	inline operator std::string() const;

	inline char *const c_string() const;

	inline size_t length() const { return _len; }

	inline bool empty() const { return _len == 0; }

	inline void clear();

	inline char &operator[](const size_t index) { return _allocator[index]; }

	inline const char operator[](const size_t index) const { return _allocator[index]; }

	inline String &operator+=(const String &);

	inline String &operator+=(const std::string &);

	inline String &operator+=(const char *);

private:
	size_t _len;
	char *_allocator;
};

inline std::ostream &operator<<(std::ostream &, const String &);

inline bool operator==(const String &one, const String &other);

inline bool operator!=(const String &one, const String &other) { return !(one == other); }

inline bool operator<(const String &one, const String &other);

inline bool operator<=(const String &one, const String &other);

inline bool operator>(const String &one, const String &other) { return !(one <= other); }

inline bool operator>=(const String &one, const String &other) { return !(one < other); }

inline String operator+(const String &one, const String &other) { return String(one) += other; }

//	String methods definitions

inline String::String() :
		_len(0),
		_allocator(NULL) {
#ifndef NDEBUG
	std::cout << "call String(), " << *this << " created" << std::endl;
	std::cout.flush();
#endif
}

inline String::String(const char *str_ptr) :
		_len(strlen(str_ptr)),
		_allocator(new char[_len]) {
	for (size_t i(0); i < _len; ++i)
		_allocator[i] = str_ptr[i];
#ifndef NDEBUG
	std::cout << "call String([char pointer]" << str_ptr << "), " << *this << " created" <<
			  std::endl;
	std::cout.flush();
#endif
}

inline String::String(const char str_char) :
		_len(1),
		_allocator(new char[_len]) {
	_allocator[0] = str_char;
#ifndef NDEBUG
	std::cout << "call String([char]" << str_char << "), " << *this << " created" <<
			  std::endl;
	std::cout.flush();
#endif
}

inline String::String(const std::string &str) :
		_len(str.length()),
		_allocator(new char[_len]) {
	for (size_t i(0); i < _len; ++i)
		_allocator[i] = str[i];
#ifndef NDEBUG
	std::cout << "call String([string]" << str << "), " << *this << " created" <<
			  std::endl;
	std::cout.flush();
#endif
}

inline String::String(const String &str, const size_t multiplayer) :
		_len(str.length() * multiplayer),
		_allocator(new char[_len]) {
	for (size_t m(0); m < multiplayer; ++m)
		for (size_t i(0); i < str.length(); ++i)
			_allocator[m * str.length() + i] = str[i];
#ifndef NDEBUG
	std::cout << "call String(" << str << ", " << multiplayer << "), " << *this << " created" <<
			  std::endl;
	std::cout.flush();
#endif
}

inline String::~String() {
#ifndef NDEBUG
	std::cout << "call ~String(" << *this << ")" <<
			  std::endl;
	std::cout.flush();
#endif
	delete[] _allocator;
};

inline String &String::operator=(const String &that) {
	if (this == &that)
		return *this;
	_len = that._len;
	delete[] _allocator;
	_allocator = new char[_len];
	for (size_t i(0); i < _len; ++i)
		_allocator[i] = that._allocator[i];
	return *this;
}

inline String &String::operator=(const std::string &that) {
	_len = that.length();
	delete[] _allocator;
	_allocator = new char[_len];
	for (size_t i(0); i < _len; ++i)
		_allocator[i] = that[i];
	return *this;
}

inline String &String::operator=(const char *str_ptr) {
	_len = strlen(str_ptr);
	delete[] _allocator;
	_allocator = new char[_len];
	for (size_t i(0); i < _len; ++i)
		_allocator[i] = str_ptr[i];
	return *this;
}

String &String::operator=(const char str_char) {
	_len = 1;
	delete[] _allocator;
	_allocator = new char[_len];
	_allocator[0] = str_char;
	return *this;
}

inline String::operator std::string() const {
	return (std::string(_allocator, _len));
}

inline char *const String::c_string() const {
	char *const result(new char[_len + 1]);
	result[_len] = 0;
	for (size_t i(0); i < _len; ++i)
		result[i] = _allocator[i];
	return result;
}

void String::clear() {
	_len = 0;
	delete[] _allocator;
	_allocator = NULL;
}

String &String::operator+=(const String &that) {
	char *new_allocator = new char[_len + that.length()];
	for (size_t i(0); i < _len; ++i)
		new_allocator[i] = _allocator[i];
	for (size_t i(0); i < that.length(); ++i)
		new_allocator[_len + i] = that[i];
	_len += that.length();
	delete[] _allocator;
	_allocator = new_allocator;
	return *this;
}

String &String::operator+=(const std::string &that) {
	char *new_allocator = new char[_len + that.length()];
	for (size_t i(0); i < _len; ++i)
		new_allocator[i] = _allocator[i];
	for (size_t i(0); i < that.length(); ++i)
		new_allocator[_len + i] = that[i];
	_len += that.length();
	delete[] _allocator;
	_allocator = new_allocator;
	return *this;
}

String &String::operator+=(const char *that_str_ptr) {
	size_t that_str_len = strlen(that_str_ptr);
	char *new_allocator = new char[_len + that_str_len];
	for (size_t i(0); i < _len; ++i)
		new_allocator[i] = _allocator[i];
	for (size_t i(0); i < that_str_len; ++i)
		new_allocator[_len + i] = that_str_ptr[i];
	_len += that_str_len;
	delete[] _allocator;
	_allocator = new_allocator;
	return *this;
}

//	String utills definitions

inline bool operator==(const String &one, const String &other) {
	if (one.length() != other.length())
		return false;
	for (size_t i(0); i < one.length(); ++i)
		if (one[i] != other[i])
			return false;
	return true;
}

inline static bool less_operator(const String &one, const String &other, const bool equal) {
	if (one.length() != other.length())
		return one.length() < other.length();
	for (size_t i(0); i < one.length(); ++i)
		if (one[i] != other[i])
			return one[i] < other[i];
	return equal;
}

inline bool operator<(const String &one, const String &other) {
	return less_operator(one, other, false);
}

inline bool operator<=(const String &one, const String &other) {
	return less_operator(one, other, true);
}

std::ostream &operator<<(std::ostream &ostream, const String &string) {
	for (size_t i(0); i < string.length(); ++i)
		ostream << string[i];
	return ostream;
}

#endif //KMA_OOP_07LAB_STRING_H
