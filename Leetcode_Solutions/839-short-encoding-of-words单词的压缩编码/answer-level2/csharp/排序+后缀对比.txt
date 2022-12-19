### 解题思路
1.对单词进行排序，排序的方法是，单词的字符从后往前对比排序
2.排序后相同后缀的肯定会相邻
3.依据后一个是否以前一个为结尾进行计算
4.如果是的话直接舍弃后一个，如果不是直接添加一个#

### 代码

```csharp
public class Solution {
 public int MinimumLengthEncoding(string[] words)
        {
            int len = words.Length;
            CompareWord compareWord = new CompareWord();
            Array.Sort(words,compareWord);
            int res = 0;
            for (int i = 0; i < len; i++)
            {
                if (i + 1 < len && words[i + 1].EndsWith(words[i]))
                {
                    //是后缀直接舍弃
                }
                else
                {
                    res += words[i].Length + 1;
                }
            }
            return res;

        }

        class CompareWord : IComparer<string>
        {
            public int Compare(string x, string y)
            {
                int len1 = x.Length;
                int len2 = y.Length;
                int minLen = Math.Min(len1, len2);
                for (int i = 0; i < minLen; i++)
                {
                    char c1 = x[len1 - 1 - i];
                    char c2 = y[len2 - 1 - i];
                    int temp = c1.CompareTo(c2);
                    if (temp != 0) return temp;
                }

                return len1.CompareTo(len2);
            }
        }
}
```