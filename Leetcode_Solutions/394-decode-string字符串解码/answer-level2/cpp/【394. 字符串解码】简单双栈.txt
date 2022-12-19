## 思路
### 代码
```c++
class Solution {
public:
    string decodeString(string s) {
        string res;
        int num = 0;
        stack<string> chars;
        stack<int> nums;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (isalpha(c)) {
                res += c;
            } else if (c == '[') {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            } else if (c == ']') {                
                //重复字符串连接
                int times = nums.top();
                for (int i = 0; i < times; ++i) {
                    chars.top() += res;
                }
                res = chars.top();
                chars.pop();
                nums.pop();
            }
        }
        return res;
    }
};
```
#### 另一种写法
```c++
class Solution {
public:
    string decodeString(string s) {
        string res;
        int num = 0;
        stack<string> chars;
        stack<int> nums;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (isalpha(c)) {
                res += c;
            } else if (c == '[') {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            } else if (c == ']') {
                string tmp = res;
                //重复字符串连接
                for (int i = 0; i < nums.top() - 1; ++i) {
                    res += tmp;
                }
                res = chars.top() + res;
                chars.pop();
                nums.pop();
            }
        }
        return res;
    }
};
```

