### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        int count=0;
        string ans="";
        for(char c: S) {
            if(count != 0) ans += c;
            if(c == '(') ++count;
            else --count;
            if(count == 0) ans.pop_back();
        }
        return ans;
    }
};
```