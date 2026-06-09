### 解题思路
你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。

请返回任意一个合法字符串。

有效「括号字符串」应当符合以下 任意一条 要求：

空字符串或只包含小写字母的字符串
可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」
 

示例 1：

输入：s = "lee(t(c)o)de)"
输出："lee(t(c)o)de"
解释："lee(t(co)de)" , "lee(t(c)ode)" 也是一个可行答案。
示例 2：

输入：s = "a)b(c)d"
输出："ab(c)d"



### 代码

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = s;
        stack<int> st; //记录未配对括号的脚标
        for(int i = 0; i<s.size();i++){
            if(s[i]=='('||s[i]==')'){
                if(st.empty()||s[i]=='(') st.push(i);
                else{
                    if(s[i]==')'&&s[st.top()]=='(') st.pop();
                    else st.push(i);
                }
            }
        }
        while(!st.empty()){
            res.erase(st.top(),1);
            st.pop();
        }
        return res;
    }
};
```