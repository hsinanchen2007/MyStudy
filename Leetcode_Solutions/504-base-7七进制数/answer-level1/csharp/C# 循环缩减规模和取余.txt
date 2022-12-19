### 解题思路

##### 1. 题目概述：七进制数

##### 2. 思路：
   - 特征：逢七进一
   - 方案：不断的对给定的树取余,以及做除法
   - 结果：每次取余结果的集合

##### 3. 知识点：数学

##### 4. 复杂度分析: 
   - 时间复杂度：O(logn)
   - 空间复杂度：O(logn)


### 代码

```csharp []
public class Solution {
        public string ConvertToBase7(int num)
        {
            if (num == 0) return "0";

            var isNeg = num < 0;
            num = Math.Abs(num);

            var constNum = 7;
            var numArray = new List<int>();
            while (num != 0)
            {
                numArray.Add(num % constNum);
                num /= constNum;
            }

            numArray.Reverse();
            var res = string.Join("", numArray);
            if (isNeg)
                res = "-" + res;

            return res;
        }
}
```