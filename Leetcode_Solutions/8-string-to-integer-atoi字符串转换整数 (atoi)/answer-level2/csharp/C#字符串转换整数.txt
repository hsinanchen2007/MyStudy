### 解题思路
本题乍一看感觉不是很难，我们只需要先将前面的空格去掉，然后看到第一个正负号记符号位，然后将符号位后面的数字位一个一个的加到我们的结果中（最好用long来保存结果，返回时转换一下就好），最后判断是否超int的界限，按要求返回即可。
但是本题有许多坑点，现在将本人踩过的坑点一一列举：
1. "-+1"
两个正负号，应当判定为无效字符串输出为0
2. "9223372036854775808"
long的最大值+1，此时用long会爆内存，可以用一个变量统计已转换的数字的位数，超过11位就停止转换（int类型的数字最多有10位，此时肯定超过了int的界限）。
3. "  0000000000012345678"
4. "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000
0000000000000000000522545459"
3和4可以放在一起说，也就是0的问题，我们可以从第一个非零的数字开始数已转换的位数，位数超过11即停止转换。

### 代码

```csharp
public class Solution {
    public int MyAtoi(string str) {
        long ans = 0;
        int i = 0, f = 1, w = 0, q = 0;
        while(i < str.Length && str[i] == ' ')
            i++;
        if (i == str.Length)
            return 0;
        if (str[i] == '-')
        {
            f = -1;
            i++;
        }
        else if (str[i] == '+')
        {
            f = 1;
            i++;
        }
        while(i < str.Length && str[i] >='0' && str[i] <= '9' && w <= 11)
        {
            ans = ans * 10 + str[i] - '0';
            if (str[i] != '0')
                q++;
            if (q != 0)
                w++;
            i++;
        }
        ans = ans * f;
        if (ans > int.MaxValue)
            return int.MaxValue;
        if (ans < int.MinValue)
            return int.MinValue;
        return (int)ans;
    }
}
```