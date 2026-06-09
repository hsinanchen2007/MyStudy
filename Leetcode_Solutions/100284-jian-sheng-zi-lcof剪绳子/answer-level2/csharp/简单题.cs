![image.png](https://pic.leetcode-cn.com/3c7d29d616c26fcf344917eb21f723d15d158a92923eb51b049e087cf9bc713b-image.png)
### 解题思路
这种题主要是找规律，代码都很简单。
拆出几组数很容易就发现与除以3的余数挂钩的。
c#抛个砖
### 代码

```csharp
public class Solution {
    public int CuttingRope(int n) {
        if (n <= 3)
        {
            return n - 1;
        }

        return (n % 3) switch
        {
            0 => Convert.ToInt32(Math.Pow(3, n / 3)),
            1 => Convert.ToInt32(Math.Pow(3, n / 3 - 1) * 4),
            _ => Convert.ToInt32(Math.Pow(3, n / 3) * 2),
        };
    }
}
```