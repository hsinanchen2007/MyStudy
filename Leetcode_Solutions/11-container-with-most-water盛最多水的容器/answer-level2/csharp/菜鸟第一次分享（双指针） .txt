### 解题思路
双指针 一个指针标记开头，另一个指针指另一条高 

### 代码

```csharp
public class Solution {
   public int MaxArea(int[] height)
        {
            int max = 0;
            int len = height.Length;
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len; j++)
                {
                    max = Math.Max((j-i) * Math.Min(height[i], height[j]) , max);
                }
            } 
            return max;
         }
}
```