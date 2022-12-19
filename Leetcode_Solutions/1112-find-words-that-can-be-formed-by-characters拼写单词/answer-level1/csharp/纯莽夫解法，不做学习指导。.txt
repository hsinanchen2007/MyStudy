### 解题思路

先收集已有字符串 chars 的字符情况，
循环遍历放进字典（哈希表）里。

再遍历字符串数组 words ，
收集每个字符串的字符情况，保存进字典里。

比对 chars 是否能满足当前字符的组成部分。

不满足则跳出循环。
满足，累加字符串的长度。

### 代码

```csharp
public class Solution
    {
        public int CountCharacters(string[] words, string chars)
        {

            int strNum = 0;

            Dictionary<char, int> charCnt = new Dictionary<char, int>();

            foreach (char item in chars)
            {
                if (charCnt.ContainsKey(item))
                {
                    charCnt[item]++;
                }
                else
                {
                    charCnt.Add(item, 1);
                }
            }

            foreach (string item in words)
            {

                if (chars.Length < item.Length)
                {
                    continue;
                }

                bool isHas = true;

                Dictionary<char, int> itemCnt = new Dictionary<char, int>();

                foreach (char c in item)
                {
                    if (itemCnt.ContainsKey(c))
                    {
                        itemCnt[c]++;
                    }
                    else
                    {
                        itemCnt.Add(c, 1);
                    }
                }

                foreach (KeyValuePair<char, int> dic in itemCnt)
                {
                    if (!charCnt.ContainsKey(dic.Key))
                    {
                        isHas = false;
                        break;
                    }

                    if (charCnt[dic.Key] < dic.Value)
                    {
                        isHas = false;
                        break;
                    }
                }

                if (isHas)
                {
                    strNum = strNum + item.Length;
                }

            }

            return strNum;
        }
    }

```