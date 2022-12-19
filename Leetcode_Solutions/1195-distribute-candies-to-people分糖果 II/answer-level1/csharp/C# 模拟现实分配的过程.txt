### 解题思路
模拟现实分配的过程，具体见注释

### 代码

```csharp
public class Solution {
    public int[] DistributeCandies(int candies, int num_people) {
        if(num_people<=1) return new int[candies];
        int[] p = new int[num_people];
        int i = 0;  // 小朋友索引，从0开始
        int circle = 0;  // 第几轮

        while(candies>0)
        {
            var current = (circle * num_people) + (i + 1); // 第 i 个小朋友在某一轮应分得的数量
            
            if(current <= candies)
            {
                // 糖果还够时
                p[i] += current;
                candies -= current;
            }
            else
            {
                // 糖果不够时
                p[i] += candies;
                candies = 0;
                break;
            }
            
            if(i == num_people - 1)
            {
                // 到了最后一个小朋友，接下来开始新的一轮
                i = 0;
                circle++;
            }
            else
            {
                i++;
            }
        }

        return p;
    }
}
```