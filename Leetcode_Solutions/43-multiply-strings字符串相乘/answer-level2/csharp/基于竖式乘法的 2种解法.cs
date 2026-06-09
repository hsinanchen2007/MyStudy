## 解法一

思路：先将字符串转换为整型数组，完全类比常规用的乘法公式，对每一位进行计算。

说明：两个非零正整数相乘的最终长度，要么等于两个数长度和，要么等于和减一1。

1. 首先排除最特殊的字符为0的情况
2. 将两个字符串分别存储到两个整型数组中
3. 分别使用两个整型数组，进行按位计算，这时下标小的位置存储低位
4. 将计算结果转换为字符，去掉最高位的0
5. 将字符结果进行反转，即高位放前面

```csharp
public class Solution {
    public string Multiply(string num1, string num2)
    {
        if(num1 == "0" || num2 == "0") 
        {
            return "0";
        }
        int n1Len = num1.Length, n2Len = num2.Length;
        int[] n1 = new int[n1Len], n2 = new int[n2Len], nr = new int[n1Len + n2Len];
        for (int i = 0; i < n1Len; i++)
        {//字符串转为数值
            n1[i] = num1[i] - '0';
        }
        for (int i = 0; i < n2Len; i++)
        {
            n2[i] = num2[i] - '0';
        }
        int t12, idx = 0;
        for (int i = n1Len - 1; i >= 0; i--, idx++)
        {//乘数
            t12 = 0;
            for (int j = n2Len - 1; j >= 0; j--, idx++)
            {//被乘数
                t12 += (n2[j] * n1[i]) + nr[idx];
                nr[idx] = t12 % 10;
                t12 /= 10;
            }
            if (t12 > 0)
            {
                nr[idx] = t12;
            }
            idx -= n2Len;
        }
        if (nr[n1Len + n2Len - 1] == 0)//判断最后一位为0，则不使用
            n2Len -= 1;
        //数值转为字符串
        char[] c = new char[n1Len + n2Len];
        for (int i = 0; i < n1Len + n2Len; i++)
            c[i] = (char)(nr[i] + '0');

        return string.Join("", c.Reverse());
    }
}
```
![20200109182033748.png](https://pic.leetcode-cn.com/1ae4db313599adb8de6c4b0551347e3d76d520554e37728e11cc9edfde484a70-20200109182033748.png)


***

## 思路二

思路：基于解法一做了两个优化，按道理应该效率提高，但执行时间还慢了4毫秒。

1. 在存储的时候，直接将结果存储到对应位置，省去了最后的反转。
2. 计算过程的进位直接给到最终值，取消临时变量idx及其对应的运算，也省去了内循环之后的判断。
3. 最后字符串拼接函数，改为实例化函数

```csharp
public class Solution {
    public string Multiply(string num1, string num2)
    {
        if(num1 == "0" || num2 == "0") 
        {
            return "0";
        }
        int n1Len = num1.Length, n2Len = num2.Length;
        int[] n1 = new int[n1Len], n2 = new int[n2Len], nr = new int[n1Len + n2Len];
        for (int i = 0; i < n1Len; i++)
        {//字符串转为数值
            n1[i] = num1[i] - '0';
        }
        for (int i = 0; i < n2Len; i++)
        {
            n2[i] = num2[i] - '0';
        }
        int t12;
        for (int i = n1Len - 1; i >= 0; i--)
        {//乘数
            for (int j = n2Len - 1; j >= 0; j--)
            {//被乘数
                t12 = (n2[j] * n1[i]) + nr[i+j+1];
                nr[i+j+1] = t12 % 10;
                nr[i+j] += t12/10;
            }
        }
        int jump = (nr[0] == 0?1:0);//判断第一位为0，则不使用
        //数值转为字符串
        char[] c = new char[n1Len + n2Len - jump];
        for (int i = jump; i < n1Len + n2Len; i++)
            c[i-jump] = (char)(nr[i] + '0');

        return string.Join("", c);
    }
}
```
![20200109192323186.png](https://pic.leetcode-cn.com/c3e6f5dfad1b1439ffef6e1ca3a3285ec5136fd21f039608f72b053fd52cc39e-20200109192323186.png)

