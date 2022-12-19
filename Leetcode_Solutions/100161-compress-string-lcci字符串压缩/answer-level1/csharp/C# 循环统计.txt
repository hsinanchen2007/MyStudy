### 解题思路

##### 1. 题目概述：字符串压缩

##### 2. 思路：
   - 特征：按照规律重造字符串;统计连续的字符个数,然后以字符加数字的方式构造新的字符串;
   - 方案：字符串遍历,始终判断当前字符串与前一个字符是否相同,相同则累加数字,否则将结果计入字符串中,开始新字符个数的统计;
   - 结果：统计的结果与原字符串比较,若更短了,则返还,否则返还原来的字符串
##### 3. 知识点：字符串

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(1)

### 代码

```csharp []
public class Solution {
        public string CompressString(string S)
        {
            if (S.Length == 0) return S;

            var forReturn = new StringBuilder();
            var charStr = S[0];
            var charCount = 1;
            for (var i = 1; i < S.Length; i++)
            {
                if (charStr == S[i])
                {
                    charCount++;
                    continue;
                }

                forReturn.Append($"{charStr}{charCount}");
                charStr = S[i];
                charCount = 1;
            }

            var strTemp = forReturn.Append($"{charStr}{charCount}").ToString();
            return strTemp.Length >= S.Length ? S : strTemp;
        }
}
```