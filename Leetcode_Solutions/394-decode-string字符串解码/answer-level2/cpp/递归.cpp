### 解题思路
遇到[，先去计算[]里面内容，然后，再去根据loop展开。

### 代码

```cpp
class Solution {
 public:
  string decodeString(const string& s) {
    int out_index = 0;
    return decode(s, 0, out_index);
  }

 private:
  string decode(const string& s, int index, int& out_index) {
    if (s.empty() || index > s.size()) {
      return "";
    }
    int loop = 0;
    string result;
    for (int i = index; i < s.size(); ++i) {
      if (isdigit(s[i])) {
        loop = loop * 10 + s[i] - '0';
      } else if (isalpha(s[i])) {
        result += s[i];
      } else if (s[i] == '[') {
        string tmp = decode(s, i + 1, i);
        loop = loop ? loop : 1;
        for (int j = 0; j < loop; ++j) {
          result += tmp;
        }
        loop = 0;
      } else if (s[i] == ']') {
        out_index = i;
        break;
      }
    }
    return result;
  }
};
```