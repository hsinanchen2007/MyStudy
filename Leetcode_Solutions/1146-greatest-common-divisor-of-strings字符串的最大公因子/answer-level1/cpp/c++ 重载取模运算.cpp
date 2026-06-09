重载运算符，然后用辗转相除法计算

```c++
#include <string>
using namespace std;

string operator%(const string& s1, const string& s2) {
  int i = 0;
  int j = 0;
  int pos = 0;
  while (s1[i] == s2[j]) {
    ++i;
    ++j;
    if (i == s1.length() && j == s2.length()) {
      return "";
    }
    if (j == s2.length()) {
      pos = i;
      j = 0;
    }
  }
  return s1.substr(pos);
}

class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    if (str1.length() < str2.length()) {
      swap(str1, str2);
    }

    while (str2 != "") {
      string tmp = str1;
      str1 = str2;
      str2 = tmp % str2;
      if (str2 == tmp) {
        return "";
      }
    }
    return str1;
  }
};
```