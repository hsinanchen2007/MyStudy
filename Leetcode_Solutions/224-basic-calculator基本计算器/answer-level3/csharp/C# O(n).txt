定义`num`为当前读入数字，`res`为当前计算表达式的值，`sign`为当前读入符号，`st`存放上一个优先级表达式的值;

遍历给定字符串，遍历到 "**+**" 或 "**-**" ，代表已经读入一个完整的`num`，此时将此`num`计入到`res`中；

遍历到 "**(**" 表示有新的优先级表达式，此时将当前表达式的值和符号推入栈并重置，以便计算下一个表达式的值；

遍历到 "**)**" 表示有当前的计算的表达式结束，此时将此表达式的值乘以栈顶符号计入到`num`，再将先前计算后压入栈中的值取出并赋给`res`;                                          


```csharp []
public class Solution
{
    public int Calculate (string s)
    {
        int res = 0, num = 0, sign = 1;
        Stack<int> st = new Stack<int>();
        for (int i = 0; i < s.Length; i++)
        {
            char c = s[i];
            if (c == ' ')
                continue;
            else if (char.IsDigit(c))
                num = num * 10 + (c - '0');
            else if (c == '+')
            {
                res += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-')
            {
                res += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(')
            {
                st.Push(res);
                st.Push(sign);
                res = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                res += sign * num;
                num = res * st.Pop();
                res = st.Pop();
                sign = 1;
            }
        }
        res += sign * num;
        return res;
    }
}
```
**时间复杂度：O(n)**                                                                                                                                     
**空间复杂度：O(n)**