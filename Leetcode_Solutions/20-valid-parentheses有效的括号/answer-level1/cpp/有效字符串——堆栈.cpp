1.设立堆栈，压入所有左括号，遇到任一右括号即开始出栈，直到匹配到对应左括号。最后若栈为空，则true；否则false。
2.第1思路无法处理”））））”类似字符串，于是补充条件，若遇到任一右括号后，此时堆栈为空，则return false。
3.上述思路无法处理“（[)”，于是补充变量left与right，分别表示左右括号数目，最后，当且仅当堆栈为空且left等于right时，return true。

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.empty())return true;

        int i=0;
        int left=0,right=0;
        stack<char> Stack;
        
        while(i<s.length())
        {
           char out='0';
           if(s[i]==')') 
           {
               right++;
               int flag=1;
               while(out!='('&&(!Stack.empty()))
               {
                   out=Stack.top();
                   Stack.pop();
               }
               if(out=='(')flag=0;
               else return false;
           }   
           else if(s[i]==']')
           {
               right++;
               int flag=1;
               while(out!='['&&(!Stack.empty()))
                {
                   out=Stack.top();
                   Stack.pop();
                }
                if(out=='[')flag=0;
                else return false;
           }    
           else if(s[i]=='}')
           {
               right++;
               int flag=1;
               while(out!='{'&&(!Stack.empty()))
               {
                   out=Stack.top();
                   Stack.pop();
                }
                if(out=='{')flag=0;
               else return false;

           }
           else
           {
               Stack.push(s[i]);
               left++;

           }

            i++;
           
        }
        
        if(Stack.empty()&&left==right)return true;
        else return false;
        
    }
};
```