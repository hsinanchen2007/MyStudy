### 解题思路
由于题目要求O(n)的复杂度，O(3n)也是O(n)的复杂度，所以，我们找三遍，找到第三大的数字输出。

### 代码

```csharp
public class Solution {
    public int ThirdMax(int[] nums) {
        int f, s, t;
        f = int.MinValue;
        s = int.MinValue;
        t = int.MinValue;
        bool b = false;
        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] >= f)
            {
                b = true;
                f = nums[i];
            }
        }
        if (b == false)
            return f;
        b = false;
        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] >= s && nums[i] < f)
            {
                b = true;
                s = nums[i];
            }
        }
        if (b == false)
            return f;
        b = false;
        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] >= t && nums[i] < s)
            {
                b = true;
                t = nums[i];
            }
        }
        if (b == false)
            return f;
        else
            return t;
    }
}
```