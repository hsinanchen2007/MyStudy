### 解题思路
1.中缀表达式转后缀表达式中间错了细节错了好长时间没找出来
错误之处：我把while写成了if....
正确代码：
把栈内优先级高的都加到逆波兰式中...while
```
 while(!opstack.empty()&&priority(opstack.top())>= priority(s[i]))
                    {
                        polish.push_back(opstack.top());
                        opstack.pop();
                    }  
                    opstack.push(s[i]);
```

2.后缀表示求解没有易错点（碰到符号就运算）
### 代码

```cpp
class Solution {
public:
   /*第一眼思路，中缀转化成后缀表达式*/
    int calculate(string s) {
        vector<char> polish;
        stack<char> opstack;
        /*将中缀表达式转化成后缀表达式*/
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' ') continue;
            if(s[i]>='0'&&s[i]<='9')
            {
                while(i<s.size()&&s[i]<='9'&&s[i]>='0')
                {
                    polish.push_back(s[i]);
                    i++;
                }
                polish.push_back(' ');
                i--;
            }
            if(s[i] == '+'||s[i] =='-'||s[i]=='*'||s[i]=='/')
            {
                if(opstack.empty()) opstack.push(s[i]);
                else 
                {
                    while(!opstack.empty()&&priority(opstack.top())>= priority(s[i]))
                    {
                        polish.push_back(opstack.top());
                        opstack.pop();
                    }  
                    opstack.push(s[i]);
                }
            }
        }
        while(!opstack.empty())
        {
            polish.push_back(opstack.top());
            opstack.pop();
        }



        /*后缀进行计算*/
        stack<int> data;
        int num;
        int a,b,c;
        for(int i=0;i<polish.size();i++)
        {
             if(polish[i] == ' ') continue;
             if(polish[i]>='0'&&polish[i]<='9')
             {
                 num = 0;
                 while(i<polish.size()&&polish[i]>='0'&&polish[i]<='9')
                 {
                     num=num*10+(polish[i] - '0');
                     i++;
                 }
                 i--;
                 data.push(num);
             }
             else if(polish[i] == '+'||polish[i] == '-'||polish[i] == '*'||polish[i] == '/')  
             {
                 b = data.top(); data.pop();
                 a = data.top(); data.pop();
                 if(polish[i] == '+') c = a+b;
                 else if(polish[i] == '-') c = a - b;
                 else if(polish[i] == '*') c = a*b;
                 else if(polish[i] == '/') c = a/b;
                 data.push(c);
             }
        }
       return data.top();
    }
    int priority(char c)
    {
         switch(c)
         {
             case '+':return 1;break;
             case '-':return 1;break;
             case '*':return 2;break;
             case '/':return 2;break;
         }
         return 0;
    }
};
```