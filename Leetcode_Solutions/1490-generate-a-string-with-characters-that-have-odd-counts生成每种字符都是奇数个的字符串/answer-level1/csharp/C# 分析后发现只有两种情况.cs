### 解题思路

##### 1. 题目概述：生成每种字符都是奇数个的字符串

##### 2. 思路：
   - 特征：提供的总个数可以为奇数,也可以为偶数;目标是让构成的字符串中,不同字符各自总数为奇数;
   - 方案：总数为奇数时,那么同种字符重复即可;总数为偶数时,2 种字符分别重复奇数次即可;后者直接设置 1 种字符 1 次,另一种字符 n-1次
   - 结果：依据以上规则生成的就是满足条件的解;

##### 3. 知识点：字符串

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(n)


### 代码

```csharp []
public class Solution {
        public string GenerateTheString(int n)
        {
            if (n % 2 == 0)
                return string.Join("", Enumerable.Repeat('a', 1)) + string.Join("", Enumerable.Repeat('b', n - 1));

            return string.Join("", Enumerable.Repeat('a', n));
        }
}
```