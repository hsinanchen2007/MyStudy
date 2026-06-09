### 解题思路
先从前向后遍历 删除前一个比后一个大的元素  根据剩余可删除个数 删除最后几位

### 代码

```csharp
public class Solution {
    public string RemoveKdigits(string num, int k) {
     if (num.Length <= k)
        {
            return "0";
        }

        int count = 0;
        int i = 1;

        while (i < num.Length && count < k)
        {
            if (num[i - 1] > num[i])
            {
                num = num.Remove(i - 1, 1);
                i--;
                if (i < 1)
                {
                    i = 1;
                }
                count++;
            }
            else
            {
                i++;
            }
        }

        if (k - count > 0)
        {
            num = num.Remove(num.Length - (k - count), k - count);
        }


        while (num.Length > 1 && num[0] == '0')
        {
            num = num.Remove(0, 1);
        }

        return num;
    }
}
```