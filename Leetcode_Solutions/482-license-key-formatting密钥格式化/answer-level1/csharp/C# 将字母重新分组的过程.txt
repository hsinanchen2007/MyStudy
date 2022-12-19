### 解题思路

##### 1. 题目概述：秘钥格式化

##### 2. 思路：
   - 特征：就是将秘钥中的字符重新分组的过程,第一组相当于是起到一个容错的作用;
   - 方案：确认原来秘钥中字符的数量,然后按照要求重新分组和构造
   - 结果：重新构造得到的字符串即为解

##### 3. 知识点：字符串

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(n)


### 代码

```csharp []
public class Solution {
        public string LicenseKeyFormatting(string S, int K)
        {
            var constChar = '-';
            var const_a = 'a';
            var subValue = const_a - 'A';
            var charArray = S.Where(i => i != constChar).ToArray();

            var forReturn = new StringBuilder(S.Length);
            for (var i = charArray.Length; i >= 1; i--)
            {
                if (i != charArray.Length && i % K == 0)
                    forReturn.Append(constChar);

                var curChar = charArray[charArray.Length - i];
                if (curChar >= const_a)
                    curChar = (char)(curChar - subValue);

                forReturn.Append(curChar);
            }

            return forReturn.ToString();
        }
}
```