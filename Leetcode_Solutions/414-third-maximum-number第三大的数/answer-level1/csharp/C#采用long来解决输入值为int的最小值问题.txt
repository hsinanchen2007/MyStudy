### 解题思路
本题较为简单，遍历一遍数组，得到第三大的数，但是有一个坑点，即输入的数字可能是int.MinValue。此时，判断会出问题，解决方法为：设置三个数字初始值为long.MinValue，此时，由于long的最小值小于int的最小值，判断就不会出问题，最后返回时，记得进行强制类型转换。

### 代码

```csharp
public class Solution {
    public int ThirdMax(int[] nums) {
        long f, s, t;
        int count = 0;
        f = long.MinValue;
        s = long.MinValue;
        t = long.MinValue;
        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] > f)
            {
                count++;
                t = s;
                s = f;
                f = nums[i];
            }
            else if(nums[i] > s && nums[i] < f)
            {
                count++;
                t = s;
                s = nums[i];
            }
            else if(nums[i] > t && nums[i] < s)
            {
                count++;
                t = nums[i];
            }
        }
        if (count < 3)
            return (int)f;
        else 
            return (int)t;
    }
}
```