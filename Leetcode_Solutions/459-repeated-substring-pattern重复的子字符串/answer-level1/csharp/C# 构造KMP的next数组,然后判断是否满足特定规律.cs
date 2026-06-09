### 解题思路

##### 1. 题目概述：检测父字符串是否是由重复的子字符串构成的

##### 2. 思路：
   - 特征：若字符串是由重复的子字符串构成的,那么 KMP 的 next 数组会满足一个特定的条件
   - 方案：使用给定的字符串去构造 next 数组,内部是DP 的实现 --> next 数组,索引和值存储的都是字符串中字符的数组下标
   - 结果：判断 next 数组是否满足一个特定的条件

##### 3. 知识点：KMP 数学

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(n)


### 代码

```csharp []
public class Solution {
        public bool RepeatedSubstringPattern(string s)
        {
            var nextArray = GetKMPNextArray(s);
            var tailIndex = s.Length - 1;
            return nextArray[tailIndex] != -1 && s.Length % (tailIndex - nextArray[tailIndex]) == 0;
        }

        private int[] GetKMPNextArray(string s)
        {
            var forReturn = Enumerable.Repeat(-1, s.Length).ToArray();
            for (var i = 1; i < s.Length; i++)
            {
                var j = forReturn[i - 1];
                while (j >= 0 && s[j + 1] != s[i])
                    j = forReturn[j];

                if (s[j + 1] == s[i])
                    forReturn[i] = j + 1;
            }

            return forReturn;
        }
}
```