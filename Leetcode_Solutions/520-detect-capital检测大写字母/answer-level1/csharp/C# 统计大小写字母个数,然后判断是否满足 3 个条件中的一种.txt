### 解题思路

##### 1. 题目概述：检测大写字母

##### 2. 思路：
   - 特征：满足要求的写法一共有 3 种:全部为大写 & 全部为小写 & 大小写都有,那么大写字母有且仅有 1 个,且必须是第一个
   - 方案：统计给定单词中大小写字母的个数;分别判断是否满足 3 个规定写法;
   - 结果：判断是否满足规定

##### 3. 知识点：字符串

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(1)


### 代码

```csharp []
public class Solution {
        public bool DetectCapitalUse(string word)
        {
            var biggerCount = 0;
            var smallCount = 0;
            foreach (var wItem in word)
            {
                if (wItem >= 'a')
                    smallCount++;
                else
                    biggerCount++;
            }

            return biggerCount == 0 || smallCount == 0 || (biggerCount == 1 && word[0] < 'a');
        }
}
```