### 解题思路

##### 1. 题目概述：四因数

##### 2. 思路：
   - 特征：因数,就是乘积等于目标值的两个数;除了 1 和自身的乘积外,仅有一对因子时,才是满足条件的解;
   - 方案：依次去判断每个数字是否为四因数,将满足条件的数字的因子累加起来;
   - 结果：累加的结果

##### 3. 知识点：因数

##### 4. 复杂度分析: 
   - 时间复杂度：O(n * sqrt(1e5))
   - 空间复杂度：O(1)


### 代码

```csharp []
public class Solution {
        public int SumFourDivisors(int[] nums)
        {
            var res = 0;
            foreach (var numItem in nums)
            {
                var maxNum = (int)Math.Sqrt(numItem);
                var count = 0;
                var sum = 0;
                for (var i = 1; i <= maxNum; i++)
                {
                    if (numItem % i == 0)
                    {
                        count++;
                        sum += i + numItem / i;
                    }

                    if (count > 2)
                        break;
                }

                if (count == 2 && maxNum * maxNum != numItem)
                    res += sum;
            }

            return res;
        }
}
```