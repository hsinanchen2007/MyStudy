### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] DistributeCandies(int candies, int num_people) 
    {  
        int i = 0;
        int[]ans = new int[num_people];

        while (candies > 0)
        {
            ans[i % num_people] += Math.Min(++i, candies);
            candies -= i;
        }

        return ans;
    }
}
```