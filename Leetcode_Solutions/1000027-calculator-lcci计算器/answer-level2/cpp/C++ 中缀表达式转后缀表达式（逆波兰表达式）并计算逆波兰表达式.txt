### 解题思路
此题主要通过如下两个步骤来完成：
1.将输入的中缀表达式转为后缀表达式（即逆波兰表达式）
2.计算逆波兰表达式
用到数据结构主要是栈（stack).

**中缀表达式转后缀表达式（逆波兰表达式）**

（1）变量及函数说明

- getPriority(char ch): 返回运算符的优先级
- vector<char> ans: 存储逆波兰表达式
- stack<char> op: 暂存未输出的运算符

（2）步骤
**i.** 如果s[i]为数字，则一直向后寻找到第一个非数字字符，并将之前的数字字符放入ans
**ii.** 如果s[i]为运算符，则分为以下三种情况：
**A.** 如果op为空，则直接将运算符s[i]压入栈op；
**B.** 如果栈op非空，且运算符s[i]的优先级高于栈顶元素的优先级，则直接将元素符s[i]压入栈op；
**C.** 如果栈op非空，且运算符s[i]的优先级低于或等于栈顶元素的优先级，则弹出栈顶元素，并将其放入ans，直到运算符s[i]的优先级高于栈顶元素的优先级，此时将运算符s[i]压入栈op.

**计算后缀表达式（逆波兰表达式）**

（1）变量说明：
- stack<int> value: 存储操作数以及中间运算结果

（2）步骤：
**1.** 如果遇到数字，则将其压入栈value;
**2.** 如果遇到运算符，则从栈value从弹出两个操作数，计算结果，并将结果压入栈value
**3.** 遍历完逆波兰表达式后，返回value栈顶元素

### 代码

```cpp
class Solution {
public:
    // get the priority of the operator
    int getPriority(char ch)
    {
        switch(ch)
        {
            case '+': return 1;
            case '-': return 1;
            case '*': return 2;
            case '/': return 2;
            default: return 0;
        }
    }
    
    // convert infix expression to postfix expression
    vector<char> toRPN(string s)
    {
        vector<char> ans;   // store the postfix expression
        stack<char> op;    // operator stack
        int len = s.length();
        for(int i = 0; i < len; ++i)
        {
            // jump the space
            if(s[i] == ' ') continue;
            
            // if s[i] is a digit, put the value into ans directly
            if(s[i] >= '0' && s[i] <= '9')
            {
                while(s[i] >= '0' && s[i] <= '9')
                {
                    ans.push_back(s[i]);
                    ++i;
                }
                ans.push_back(' ');
                --i;
            }
            // if s[i] is an operator
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                // if op is empty, push s[i] directly
                if(op.empty()) op.push(s[i]);
                // if op is not empty, we should compare the priority
                else
                {
                    if(getPriority(s[i]) > getPriority(op.top()))
                        op.push(s[i]);
                    else
                    {
                        while(!op.empty() && (getPriority(s[i]) <= getPriority(op.top())))
                        {
                            ans.push_back(op.top());
                            ans.push_back(' ');
                            op.pop();
                        }
                        op.push(s[i]);
                    }
                }
                
            }
        }
        while(!op.empty())
        {
            ans.push_back(op.top());
            ans.push_back(' ');
            op.pop();
        }
        return ans;
    }

    int calculateRPN(vector<char> str)
    {
        int len = str.size();
        int value1, value2, ans;
        stack<int> value;
        for(int i = 0; i < len; ++i)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                int tmp = str[i] - 48;
                int j = ++i;
                while(str[j] >= '0' && str[j] <= '9')
                {
                    tmp = tmp * 10 + (str[j] - 48);
                    ++j;
                }
                value.push(tmp);
                i = --j;
            }
            if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            {
                value2 = value.top();
                value.pop();
                value1 = value.top();
                value.pop();
                if(str[i] == '+') ans = value1 + value2;
                else if(str[i] == '-') ans = value1 - value2;
                else if(str[i] == '*') ans = value1 * value2;
                else ans = value1 / value2;
                value.push(ans);
            }
        }
        return value.top();
    }

    int calculate(string s) {
        return calculateRPN(toRPN(s));
    }
};
```