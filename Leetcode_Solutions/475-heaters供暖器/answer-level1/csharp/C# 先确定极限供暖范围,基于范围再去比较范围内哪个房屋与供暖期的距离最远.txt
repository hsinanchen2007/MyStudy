### 解题思路

##### 1. 题目概述：供暖器

##### 2. 思路：
   - 特征：房屋和暖炉都是分散排布的,且位置固定;最左/右暖炉需要负责左/右所有房屋的供暖;两个暖炉之间,以它们的中点为界,各自负责区域内房屋的供暖;
   - 方案：把每个暖炉看作是一个"桶",桶的范围内的房屋,都是一个暖炉负责的;检查每个桶,看下供暖器与房屋的最大距离是多少
   - 结果：供暖期与房屋的最大距离,即为所求的解

##### 3. 知识点：数组

##### 4. 复杂度分析: n 表示房屋的数量,m 表示供暖期的数量 
   - 时间复杂度：O(n+m)  O(nlogn) O(mlogm)
   - 空间复杂度：O(m)


### 代码

```csharp []
public class Solution {
        public int FindRadius(int[] houses, int[] heaters)
        {
            var orderHourses = houses.OrderBy(i => i).ToArray();
            var orderHeaters = heaters.OrderBy(i => i).ToArray();

            var heatRange = new int[orderHeaters.Length + 1];
            for (var i = 0; i < orderHeaters.Length - 1; i++)
                heatRange[i + 1] = (orderHeaters[i] + orderHeaters[i + 1]) / 2;
            heatRange[orderHeaters.Length] = int.MaxValue;

            var forReturn = 0;
            var heatIndex = 0;
            foreach (var hourseItem in orderHourses)
            {
                while (heatRange[heatIndex + 1] < hourseItem)
                    heatIndex++;

                forReturn = Math.Max(forReturn, Math.Abs(orderHeaters[heatIndex] - hourseItem));
            }

            return forReturn;
        }
}
```