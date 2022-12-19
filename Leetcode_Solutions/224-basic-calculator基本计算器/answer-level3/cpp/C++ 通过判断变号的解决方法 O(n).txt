不想直接用传统的两个栈或者递归方法解决，就激情搞了个投机取巧的去括号方法，还可继续优化，现在很困意思到了就行。

执行用时 :16 ms, 在所有 C++ 提交中击败了93.35%的用户。

内存消耗 :10.3 MB, 在所有 C++ 提交中击败了78.19%的用户。

用 `prev` 栈记录括号前的符号，判断是否需要变号并用 `reverse` 变量表示。

```gradle
class Solution {
public:
    int calculate(string s) {
        long long num = 0;//存放单个数字
        long long result = 0;//存放结果
        stack<char>prev;//括号前的符号正负，决定括号内部是否需要变号（为-则括号内需要变号）
        while(!prev.empty())prev.pop();
        prev.push('#');
        bool reverse = false;//是否需要变号（+变-，-变+）
        bool first = true;//是不是第一个数字（第一个直接赋值给result）
        int sign = 1;//1为加，-1为减
        //bool change = false;//与前一个符号相对来说是否变号，即是否对reverse的值进行修改
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' '||s[i]=='\"')continue;
            else if(s[i]>='0'&&s[i]<='9')
            {
                num = num * 10 + (s[i] - '0');
                while(s[i+1]==' ')i++;
                if((s[i+1]<'0'||s[i+1]>'9')||i+1>=s.length())//是完整数字
                {
                    if(first)
                    {
                        result = num;
                        first = false;
                    }
                    else
                    {
                        result += sign * num;
                 
                    }
                }
            }
            else
            {
                if(s[i]=='+')
                {
                    while(s[i+1]==' ')i++;
                    if(s[i+1]=='(')prev.push(s[i]);
                    if(reverse)//需要变号
                    {
                        sign=-1;
                        num = 0;
                    }
                    else
                    {
                        sign=1;
                        num = 0;
                    }
                    
                }
                else if(s[i]=='-')
                {
                    while(s[i+1]==' ')i++;
                    if(s[i+1]=='(')prev.push(s[i]);
                    if(reverse)//需要变号
                    {
                        sign=1;
                        num = 0;
                    }
                    else
                    {
                        sign=-1;
                        num = 0;
                    }
                }
                else if(s[i]=='(')
                {
                    if(prev.top()=='-')//之前是减号，内部需要将符号置反
                    {
                        reverse = !reverse;
                    }
                    else ;
                    num = 0;
                }
                else if(s[i]==')')
                {
                    if(prev.top()=='-')//这个括号范围内reverse有修改，则结束后需要还原
                    {
                        reverse = !reverse;
                        prev.pop();
                    }
                    else prev.pop();
                    num = 0;
                }
            }
        }
        return result;
    }
};
```
