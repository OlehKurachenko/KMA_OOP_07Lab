# KMA_OOP_07Lab

### Task

Task was to implement the following. Conscious changes were allowed.

```cpp
class String {
private:
  size_t _len;
  char* _allocator;
  
public:
  class BadString;

  class BadIndex;

  String();

  explicit String(constchar*);

  String(constchar);

  explicit String(const string&);

  String(const String & s, int multiplayer = 1);

  ~String();

  String& operator=(const String&);

  String& operator=(const string&);

  String& operator=(constchar*);

  String& operator=(constchar);

  const string STL_string() const;

  const char* c_str() const;

  size_t length() const;

  bool empty() const;

  void clear();

  char& operator[](size_t);

  const char operator[](size_t) const;

  bool operator==(const String&) const;

  bool operator!=(const String&) const;

  bool operator< (const String&) const;

  bool  operator<=(const String&) const;

  bool operator> (const String&) const;

  bool operator>=(const String&) const;

  String operator+(const String&) const;

  String& operator=(const String&);

  String& operator=(const string&);

  String& operator+=(constchar*);

  String& operator+=(const String&);

  String& operator+=(const string&);
};

ostream& operator<<(ostream&, const String&);
```
