### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
 public:
  string decodeString(const string& s) {
    stack<string> result_stack;
    stack<int> loop_stack;
    int loop = 0;
    string result;
    for (const auto& c : s) {
      if (isdigit(c)) {
        loop = loop * 10 + c - '0';
      } else if (isalpha(c)) {
        result += c;
      } else if (c == '[') {
        result_stack.push(result);
        loop_stack.push(loop ? loop : 1);
        result = "";
        loop = 0;
      } else if (c == ']') {
        string tmp;
        for (int i = 0; i < loop_stack.top(); ++i) {
          tmp += result;
        }
        result = result_stack.top() + tmp;
        loop_stack.pop();
        result_stack.pop();
      }
    }
    return result;
  }
};
```