### 解题思路
使用栈来解决：
1、遇到左括号就进栈
2、遇到右括号就与栈顶的进行配对，只要右括号出现，就必有左括号与之配对，而且这个左括号也必须在栈顶，否则返回false。
3、如果到最后栈为空，则全部匹配成功

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<int> mystack;
        for(int i=0;i<s.size();i++)
        {   

            if(s[i]=='{' || s[i]=='[' || s[i]=='(')
            {
                mystack.push(s[i]);
            }
            else
            {
                if(mystack.empty())
                {
                    return false;
                }

                char c = mystack.top();
                mystack.pop();

                switch(s[i])
                {
                    case '}': 
                        if(c == '{'){break;}
                        else{ return false;}
                    case ']': 
                        if(c == '['){break;}
                        else{ return false;}
                    case ')': 
                        if(c == '('){break;}  
                        else{ return false;}

                    default: return false;
                    
                }


            }

            
        }

        if(mystack.empty())
        {
            return true;
        }
        else
        {
            return false;
            
        }
        

    }
};
```