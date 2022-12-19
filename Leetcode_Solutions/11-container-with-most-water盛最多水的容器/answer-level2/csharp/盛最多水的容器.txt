### 解题思路
双指针法

### 代码

```csharp
public class Solution {
    public int MaxArea(int[] height)
        {
            int left = 0;
            int right = height.Length - 1;
            int result = 0;

            while (left < right)
            {
                var currentValue = (right - left) * Math.Min(height[left], height[right]);
                result = Math.Max(result, currentValue);
                if (height[left] > height[right])
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }

            return result;
        }
}
```