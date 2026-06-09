
**双100%，一步步走就完事了**


```cpp
class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        bool isNum = false;

        int p = 0, sLen = s.size();
        while (p < sLen && s[p] == ' ') p++;                    // ①去空格
        if (p < sLen && (s[p] == '+' || s[p] == '-')) p++;      // ②可以存在符号
        while (p < sLen && isdigit(s[p])) {                     // ③数字（可以为空）
            p++;
            isNum = true;
        }
        if (p < sLen && s[p] == '.') p++;                       // ④可以存在点
        while (p < sLen && isdigit(s[p])) {                     // ⑤数字（可以为空，但是③⑤不能同时为空）
            p++;
            isNum = true;
        }

        if(p < sLen && isNum && s[p] == 'e') {                  // ⑥可以存在指数幂
            p++;
            isNum = false;
            if (p < sLen && (s[p] == '+' || s[p] == '-')) p++;  // ⑦幂可以有符号
            while (p < sLen && (isdigit(s[p]))) {               // ⑧数字（不可为空）
                p++;
                isNum = true;
            }
        }
        
        while (p < sLen && s[p] == ' ') p++;                    // ⑨去除末尾空格
        return isNum && p == s.size();
    }
};
```
