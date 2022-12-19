### 解题思路
1、遍历s，将每个字符的下标和字符以pair形式入栈；
2、当遇到括号匹配时，利用reverse函数翻转从st.top()的下标到当前元素下标之间的字符串；
3、最终将s中所有的括号去掉，得到最终结果。

### 代码

```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        stack<pair<char,int>> st;
        string ans;
        for(int i=0;i<s.size();++i){
            if(!st.empty() && st.top().first=='('&& s[i]==')'){
                reverse(s.begin()+st.top().second+1,s.begin()+i);
                st.pop();
            }
            else{
                if(s[i]=='('|| s[i]==')') st.push(make_pair(s[i],i));
            }
        }
        for(int i=0;i<s.size();++i){
            if(s[i]=='('|| s[i]==')'){
                continue;
            }
            else ans+=s[i];
        }
        return ans;
    }
};
```