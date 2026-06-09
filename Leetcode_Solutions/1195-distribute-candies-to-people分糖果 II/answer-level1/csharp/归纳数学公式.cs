### 解题思路
数学公式求解

### 代码

```csharp
public class Solution {
    public int[] DistributeCandies(int candies, int num_people) {
            int rows = 0;
            for (int i = 0; i < candies; i++)
            {
                if (num_people * i * (num_people * i + 1) / 2 <= candies && num_people * (i + 1) * (num_people * (i + 1) + 1) / 2 > candies)
                {
                    rows = i;
                    break;
                }
            }
            int[] result = new int[num_people];
            for (int i = 0; i < num_people; i++)
            {
                result[i] = rows * (i + 1) + num_people * rows * (rows - 1) / 2;
            }
            int rest = candies - num_people * rows * (num_people * rows + 1) / 2;
            for (int i = 0; i < num_people; i++)
            {
                if (rest >= rows * num_people + i + 1)
                {
                    result[i] += rows * num_people + i + 1;
                    rest = rest - (rows * num_people + i + 1);
                }
                else
                {
                    result[i] += rest;
                    break;
                }
            }
            return result;
        
    }
}
```