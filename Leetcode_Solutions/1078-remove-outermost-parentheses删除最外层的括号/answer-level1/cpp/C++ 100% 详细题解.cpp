
## 思路
- 类似于栈的匹配（不看这句也没有关系）
- 遇到'(' 就把l加一，遇到')'就把l减一，当l重新归于零时，说明左右括号刚好匹配，这时找到一组原语。
- 然后删除该原语的最外层括号，这里用mark记录原语的第一个左括号。
```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans = "";
        int l = 0, mark = 0;
        for(char i : S){
            if(i == '(')    ++ l;
            else -- l;
            if(l == 0){
                ans.erase(ans.begin() + mark);
                mark = ans.size();
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```
