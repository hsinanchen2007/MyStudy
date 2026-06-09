
看了大部分题解，我的这份代码应该是比较简短的。除了一个递归也没什么其它特别的trick，跑了几次最快4ms，最慢28ms，基本是稳定12ms
```c++
class Solution {
public:
    int calculate(string s) {
        int idx = 0;
        return calculate(s, idx);
    }
    int calculate(string &s, int &idx) {
        int i = 0, mode = 0;        // mode用来标记是+还是-
        for (; idx < s.size(); ++idx) {
            if(s[idx] == '(')
                i = mode == 0 ? i + calculate(s, ++idx) : i - calculate(s, ++idx);
            else if(s[idx] >= '0' && s[idx] <= '9')
                i = mode == 0 ? i + parseNum(s, idx) : i - parseNum(s, idx);
            else if(s[idx] == '-') mode = 1;
            else if(s[idx] == '+') mode = 0;
            else if(s[idx] == ')') break;
        }
        return i;
    }
    int parseNum(string &s, int &idx) {  // 用来转换字符串中数字
        int i = 0;
        while(idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
            i = i * 10 + (s[idx] - '0');
            ++idx;
        }
        --idx;          // idx指向数字最后一位
        return i;
    }
};
```