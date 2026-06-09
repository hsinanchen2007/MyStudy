### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(ss.empty())
            {
                ss.push(s[i]);
            }
            else
            {
                bool a=(ss.top()==')'||ss.top()==']'||ss.top()=='}'); //一开始放)]}的直接报错
                bool b=(ss.top()=='('&&(s[i]==']'||s[i]=='}'));
                bool c=(ss.top()=='['&&(s[i]==')'||s[i]=='}'));
                bool d=(ss.top()=='{'&&(s[i]==')'||s[i]==']'));
                bool e=((ss.top()=='('&&s[i]==')')||(ss.top()=='['&&s[i]==']')||(ss.top()=='{'&&s[i]=='}')); //括号成对
                if(a||b||c||d)
                {
                    return false;
                }
                else if(e)
                {
                    ss.pop();
                }
                else
                {
                    ss.push(s[i]);  //非成对却都是左括号，往栈里面放即可
                }
            }
        }
        if(!ss.empty())
        {
            return false;
        }
        else
        {
            return true;      //全部成对是有效括号
        }
    }
    stack<int>ss;//维护一个栈,只存左括号
};
```