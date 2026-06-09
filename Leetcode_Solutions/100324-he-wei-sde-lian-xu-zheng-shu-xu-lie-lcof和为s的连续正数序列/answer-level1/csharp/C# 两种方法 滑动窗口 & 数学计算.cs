### 解题思路

##### 1. 题目概述：和为目标值的连续正整数序列

##### 2. 思路：
   - 特征：满足条件的序列是连续的;
   - 方案：考虑使用滑动窗口的方式;滑动窗口的两个边界一定是向右移动的,左边界移动总和变小,右边界移动总和变大;当总和与目标值一致时,这个连续的序列就是一个可行解;
   - 结果：找到的多个可行解,即为题目所需的解

##### 3. 知识点：滑动窗口

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(1)


### 代码

```csharp []
public class Solution {
        public int[][] FindContinuousSequence(int target)
        {
            var forReturn = new List<int[]>();

            var smallNum = 1;
            var bigNum = 2;
            var sum = smallNum + bigNum;
            var limitNum = target / 2;
            while (true)
            {
                if (smallNum > limitNum) break;

                if (sum < target)
                    sum += ++bigNum;
                else if (sum > target)
                    sum -= smallNum++;
                else
                {
                    forReturn.Add(Enumerable.Range(smallNum, bigNum - smallNum + 1).ToArray());
                    sum += ++bigNum;
                }
            }

            return forReturn.ToArray();
        }
}
```

### 解题思路

##### 1. 题目概述：和为目标值的连续正整数序列

##### 2. 思路：
   - 特征：目标值是固定的;连续的正整数,是等差为 1 的数列;
   - 方案：把连续序列看作是"基数+增量"组成的序列,增量的和 + 基数*个数 = target,依据这个公式不断去寻找满足要求的序列
   - 结果：满足要求序列的集合,就是所需的解

##### 3. 知识点：数组

##### 4. 复杂度分析: 
   - 时间复杂度：O(根号 n)
   - 空间复杂度：O(1)


### 代码

```csharp []
public class Solution {
        public int[][] FindContinuousSequence(int target)
        {
            var forReturn = new List<int[]>();
            var increaseNumSum = 0;
            var increaseNum = 1;
            while (true)
            {
                increaseNumSum += increaseNum++;

                if (increaseNumSum >= target)
                    break;

                var subValue = target - increaseNumSum;
                if (subValue % increaseNum == 0)
                {
                    var startNum = subValue / increaseNum;
                    var intArray = Enumerable.Range(startNum, increaseNum).ToArray();

                    forReturn.Add(intArray);
                }
            }

            forReturn.Reverse();
            return forReturn.ToArray();
        }
}
```