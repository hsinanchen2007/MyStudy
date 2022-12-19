

```
class Solution {
public:
    bool isValid(string s) 
    {
        stack<int>push;
        if(s.size()%2>1)return false;//如果长度为奇数则匹配失败

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{' )//遇到左括号就进栈
            else if(s[i]==')' || s[i]==']' || s[i]=='}')
            {//先判断是否为他们其中的一个 在进行细分比较
                if(push.empty())return false;//如果栈为空则没有与右括号匹配的左括号
                if(s[i]==')'){if(push.top()!='(')return false;}
                if(s[i]==']'){if(push.top()!='[')return false;}
                if(s[i]=='}'){if(push.top()!='{')return false;}
                push.pop();//有匹配之后 一定要出栈  为下一次的匹配准备
            }
            else return false;//排除字符串中有空格等其他符号的情况
        }
      return push.empty();//栈空了代表已经匹配完成
    }
};
```
