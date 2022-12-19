### 解题思路
使用了马拉车算法。这个算法的核心就是，在大的回文里，小的回文也会对称的。只要注意到了这点，其他的就不难理解了。必要时可以画一个图帮助理解。

### 代码

```csharp
    public class Solution
    {
        public string Preprocess(string text)
        {
            int i = -1;
            StringBuilder result = new StringBuilder("^");

            while (++i < text.Length)
            {
                result.Append("#" + text[i]);
            }

            result.Append("#$");

            return result.ToString();
        }

        public string  LongestPalindrome (string text)
        {
            string preprocessedText = Preprocess(text);

            int[] p = new int[preprocessedText.Length];
            int c = 0, r = 0;

            for(int i=1; i < preprocessedText.Length-1; i++)
            {
                int i_mirror = 2 * c - i;

                if (r > i)
                {
                    p[i] = Math.Min(r - i, p[i_mirror]);
                }
                else
                {
                    p[i] = 0;
                }

                while (preprocessedText[i + 1 + p[i]] == preprocessedText[i - 1 - p[i]])
                {
                    p[i]++;
                }

                if(i+p[i] > r)
                {
                    r = i + p[i];
                    c = i;
                }
            }

            int maxLen = 0;
            int centerIndex = 0;

            for(int i=1; i< preprocessedText.Length-1; i++)
            {
                if (p[i] > maxLen)
                {
                    maxLen = p[i];
                    centerIndex = i;
                }
            }

            int startIndex = (centerIndex - maxLen) / 2;

            return text.Substring(startIndex, maxLen);
        }
    }
```