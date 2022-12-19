### 解题思路

##### 1. 题目概述：构造矩形

##### 2. 思路：
   - 特征：找到两个数字,乘积为目标值;两个数字的差距越小越好;
   - 方案：求得一个数字的平方根,若此值的平方刚好等于目标值,这个就是结果了,否则,就逐渐逐渐减小最小值
   - 结果：逐渐拉开最大最小值的差距,找到的第一个可行解,即为目标解

##### 3. 知识点：双指针

##### 4. 复杂度分析: 
   - 时间复杂度：O(根号 area)
   - 空间复杂度：O(1)


### 代码

```csharp解一 []
public class Solution {
        public int[] ConstructRectangle(int area)
        {
            var minNum = (int)Math.Sqrt(area);

            while (area % minNum != 0)
                minNum--;

            return new int[] { area / minNum, minNum };
        }
}
```
```csharp解二 []
public class Solution {
        public int[] ConstructRectangle(int area)
        {
            var middle = (int)Math.Sqrt(area);

            var minNum = middle;
            var maxNum = middle;
            while (true)
            {
                var result = minNum * maxNum;
                if (result == area)
                    break;

                if (result > area)
                    minNum = Math.Min(--minNum, result / maxNum);
                else
                    maxNum = Math.Max(++maxNum, result / minNum);
            }

            return new int[] { maxNum, minNum };
        }
}
```