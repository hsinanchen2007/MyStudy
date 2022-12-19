### 解题思路
给出一个字符串 s（仅含有小写英文字母和括号）。

请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。

注意，您的结果中 不应 包含任何括号。

示例 1：

输入：s = "(abcd)"
输出："dcba"
示例 2：

输入：s = "(u(love)i)"
输出："iloveu"



### 代码

```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        string res = s;
        stack<int> st;
        int r(0),l(0);
        for(int i = 0; i<s.size();i++){
            if(s[i]=='(') {
                st.push(i);
                res[i] =' ';
            }
            else if(s[i]==')'&&!st.empty()){
                reverse(res.begin()+st.top()+1,res.begin()+i);
                st.pop();
                res[i] =' ';
            }
        }
        res.erase(remove(res.begin(),res.end(),' '),res.end());
        return res;  
    }
};
```

不知道有啥好的建议，能省去最后删除括号的步骤？