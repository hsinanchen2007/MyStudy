### 解题思路
按照空格分割字符串，然后放进堆栈，然后依次读取打印。但这里面涉及到几种字符串或者字符的转换，总的来说，字符处理 就这几招。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        if(s.length() == 0) {
            return string("");
        }

        // 1、string转char[] s.data()
        const char* seg = " ";
        auto p = strtok(s.data(), seg);

        // 2、save result to stack
        stack<string> res;
        while(p) {
            //cout << p << endl;
            res.push(p);
            p = strtok(NULL, seg);
        }

        // 3、print to string
        string ret;
        while(!res.empty()) {
            if(ret.length() == 0) {
                ret = res.top();
            } else {
                ret += " " + res.top();
            }
            res.pop();
        }

        return ret;
    }
};
```