### 解题思路

##### 1. 题目概述：学生出勤记录

##### 2. 思路：
   - 特征：依据规则分析字符串,得到结果;不能有两个A;不能有 LLL;
   - 方案：一次遍历,做统计;遇到 A,就累计;遇到连续的 L 也累计;
   - 结果：期间任何不满足都是 false;

##### 3. 知识点：字符串

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(1)


### 代码

```csharp []
public class Solution {
        public bool CheckRecord(string s)
        {
            var aCount = 0;
            var lCount = 0;
            foreach (var sItem in s)
            {
                switch (sItem)
                {
                    case 'A':
                        aCount++;
                        if (aCount > 1) return false;

                        lCount = 0;
                        break;

                    case 'L':
                        lCount++;
                        if (lCount > 2) return false;

                        break;

                    case 'P':
                        lCount = 0;
                        break;
                }
            }

            return true;
        }
}
```