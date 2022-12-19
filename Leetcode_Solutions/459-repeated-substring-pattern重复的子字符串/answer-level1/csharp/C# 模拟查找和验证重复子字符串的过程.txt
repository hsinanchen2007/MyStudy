### 解题思路

##### 1. 题目概述：重复的子字符串

##### 2. 思路：
   - 特征：子字符串组成原始字符串,那么个数上一定是倍数关系;子字符串的最大长度是原始字符串的一半;判断是否足以构成,那就只能去挨个字符的判断了;
   - 方案：遍历长度 1 ~ 原始串的一半,找到可整除原始串长度的子长度,然后去判断这个字串是否可以构成原始串
   - 结果：一旦找到一个满足条件的,那么就是 true,否则就是 false

##### 3. 知识点：字符串

##### 4. 复杂度分析: 
   - 时间复杂度：O(n^2)
   - 空间复杂度：O(n)


### 代码

```csharp []
public class Solution {
        public bool RepeatedSubstringPattern(string s)
        {
            for (var i = 1; i <= s.Length / 2; i++)
                if (s.Length % i == 0 && IsRepeat(s, i)) return true;

            return false;
        }

        private bool IsRepeat(string s, int subLength)
        {
            var subStr = s.Substring(0, subLength);
            for (var i = subLength; i < s.Length; i++)
                if (subStr[i % subLength] != s[i]) return false;

            return true;
        }
}
```