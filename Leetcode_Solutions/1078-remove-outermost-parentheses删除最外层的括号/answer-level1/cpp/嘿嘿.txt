### 解题思路
遇到判断合法括号的题，第一反应一定不是想到栈，而是想到遇到左括号++，右括号--

### 代码

```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ret;
        int i=0,j;
        int cnt = 0;
        int len = S.length();
        for (j=0; j<len; ++j) {
            if (S[j] == '(') ++cnt;
            else --cnt;
            if (cnt == 0) {
                ret += S.substr(i+1,j-i-1);
                i = j+1;
            }
        } 
        return ret;
    }
};
```