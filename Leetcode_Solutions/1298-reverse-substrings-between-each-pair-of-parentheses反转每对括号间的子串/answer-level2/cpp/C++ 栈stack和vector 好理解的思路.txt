### 解题思路
1 利用一个栈ss存放括号
2 利用一个vector容器a存放每个括号的索引
每个括号入栈，对应的索引进入容器，同时连续的一对括号‘（’和‘）’出栈，同时利用其对应的索引号对原字符串进行反转，然后pop掉对应索引
最后去除反转后的字符串中所有的括号
![m.png](https://pic.leetcode-cn.com/c8b935b6684283a22de0262d326160959efbd9467923a110ad339cfb4502f90f-m.png)

### 代码

```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>ss;
        vector<int>a;
        for(int i=0;i<s.size();i++){
            if(!ss.empty()){
                if(ss.top()=='('&&s[i]==')'){
                    reverse(s.begin()+a.back()+1,s.begin()+i);                
                    ss.pop();
                    a.pop_back();
                    continue;
                }
                if(s[i]=='('){
                    ss.push(s[i]);
                    a.push_back(i);
                }
            }
            else if(s[i]=='('){
                ss.push(s[i]);
                a.push_back(i);
            }
        }
        //去除所有的括号
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]==')'){
                s.erase(s.begin()+i);
                i--;
            }         
        }
        return s;
    }
};
```