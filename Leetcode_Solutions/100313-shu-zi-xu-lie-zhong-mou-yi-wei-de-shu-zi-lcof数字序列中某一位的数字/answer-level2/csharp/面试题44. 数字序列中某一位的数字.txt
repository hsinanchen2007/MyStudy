### 解题思路
数学分析法
1位数字总字符长度：10x1
2位数字总字符长度：90x2
3位数字总字符长度：900x3
4位数字总字符长度：9000x4
...


### 代码

```csharp
public class Solution {
    public int FindNthDigit(int n) {
        long length = 1;
        long count = 10;
        long tenBase = 9;
        long lastCount = 0;
        // 求出n所命中的数字的总位数
        while (count < n)
        {
            length++;
            tenBase *= 10;
            var currentCount = tenBase * length;
            lastCount = count;
            count += currentCount;
        }

        // n代表的字符在该位所有数字字符串中的索引
        var remainder = n - lastCount;
        // 计算n所命中的数字
        var value = remainder / length;
        if (length > 1)
        {
            value += (int)Math.Pow(10, length - 1);
        }
        // 计算目标字符在数字的第几位
        remainder %= length;
        return value.ToString()[(int)remainder] - '0';
    }
}
```