### 解题思路

先通过遍历将字符串中的字数保存在字典（哈希表）里，

再遍历哈希表的值，字数是偶数的直接加，
奇数的减一后再加。
最后确保有最大奇数，加上中间的1就行。

### 代码

```csharp
public class Solution
    {
        public int LongestPalindrome(string s)
        {
            int strLength = 0;

            Dictionary<char, int> dic = new Dictionary<char, int>();

            foreach (char c in s)
            {
                if (dic.ContainsKey(c))
                {
                    dic[c]++;
                }
                else
                {
                    dic.Add(c, 1);
                }
            }

            int num = 0;

            foreach (var item in dic)
            {
                if (item.Value % 2 == 0)
                {
                    strLength += item.Value;
                }
                else
                {
                    strLength += item.Value - 1;

                    if (item.Value > num)
                    {
                        num = item.Value;
                    }
                }
            }

            if (num > 0)
            {
                strLength += 1;
            }

            return strLength;
        }
    }
```