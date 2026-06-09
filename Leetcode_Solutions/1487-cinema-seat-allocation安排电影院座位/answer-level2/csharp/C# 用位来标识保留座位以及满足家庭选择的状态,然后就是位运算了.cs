### 解题思路

##### 1. 题目概述：安排电影院座位

##### 2. 思路：
   - 特征：把每一排座位都看成是二进制的 10 个位;那么保留的座位可以用数字来表示状态;满足条件的座位也可以用数字来表示状态;
   - 方案：座位数非常之多,达到 1e9,然而被保留的座位仅仅是 1e4 的数量级,所以循环每排座位是不可行的;其实只要没有人预定,那么肯定是可以坐 2 个家庭的;只需要循环被预约的座位,看一下是否满足坐几个家庭的需求;
   - 结果：累加的结果

##### 3. 知识点：位运算

##### 4. 复杂度分析: r 表示被预约座位的排数 
   - 时间复杂度：O(r)
   - 空间复杂度：O(r)


### 代码

```csharp []
public class Solution {
        public int MaxNumberOfFamilies(int n, int[][] reservedSeats)
        {
            if (m_others == null)
            {
                var first = 0;
                for (var i = 2; i <= 9; i++)
                    first |= 1 << i;
                m_first = first;

                var second = 0;
                for (var i = 2; i <= 5; i++)
                    second |= 1 << i;

                var third = 0;
                for (var i = 6; i <= 9; i++)
                    third |= 1 << i;

                var four = 0;
                for (var i = 4; i <= 7; i++)
                    four |= 1 << i;

                m_others = new HashSet<int>() { second, third, four };
            }

            var dic = reservedSeats
                .GroupBy(i => i[0], j => j[1])
                .ToDictionary(i => i.Key, j => j.Aggregate(0, (t, i) => t | (1 << i)));

            var forReturn = (n - dic.Count) * 2;
            foreach (var dicItem in dic)
            {
                if ((dicItem.Value & m_first) == 0)
                    forReturn += 2;
                else if (m_others.Any(i => (dicItem.Value & i) == 0))
                    forReturn++;
            }

            return forReturn;
        }

        private static int m_first;
        private static HashSet<int> m_others;
}
```