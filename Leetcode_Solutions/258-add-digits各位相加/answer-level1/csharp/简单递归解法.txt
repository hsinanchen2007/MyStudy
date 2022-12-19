### 解题思路
简单递归解法
递归计算每一次循环相加的和，大于9则继续，直到取得一个小于10的结果

### 代码

```csharp
public class Solution {
    public int AddDigits(int num) {
        int temp = GetNum(num);
        while (temp > 9)
        {
            temp = GetNum(temp);
        }
        return temp;
    }

    private int GetNum(int num)
    {
        int temp = 0;
        while (num > 0)
        {
            temp += num % 10;
            num = num / 10;
        }
        return temp;
    }
}
```