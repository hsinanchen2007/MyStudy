### 解题思路一
使用 `OrderedDictionary` 来储存frequency，当出现超过一次时，直接移除旧的记录，然后添加一个值为false的记录。

我本来是想通过使用OrderedDictionary来
1. 避免使用额外的属性来记录该 char 第一次出现的index
2. 繁琐的 List 查询，看是否存在于该 List 中

可是目前看来，`OrderedDictionary` 相较于 Dictionary 的优势，并没有那么明显。（或者我使用方法错了）

### 代码
```csharp
using System.Collections.Specialized;

public class Solution 
{
    public char FirstUniqChar(string s)
    {
        // 执行用时: 776 ms, 在所有 C# 提交中击败了 5.88% 的用户
        // 内存消耗: 36.9 MB, 在所有 C# 提交中击败了 100.00% 的用户
        OrderedDictionary freqDictionary = new OrderedDictionary();
        for (int i = 0; i < s.Length; i++)
        {
            char currentChar = s[i];
            if (freqDictionary.Contains(currentChar))
            {
                freqDictionary.Remove(currentChar);
                freqDictionary.Add(currentChar, false);
            }
            else
            {
                freqDictionary.Add(currentChar, true);
            }
        }

        try
        {
            foreach (DictionaryEntry dictionaryEntry in freqDictionary)
            {
                bool? uniqChar = dictionaryEntry.Value as bool?;
                if (uniqChar.HasValue && uniqChar.Value)
                {
                    char? uniqCharKey = dictionaryEntry.Key as char?;
                    return uniqCharKey.HasValue ? uniqCharKey.Value : ' ';
                }
            }

            return ' ';
        }
        catch
        {
            return ' ';
        }
    }
}
```

### 解题思路二
使用一个 `Dictionary<char, (int, int)>` 来储存 char 的频率和首次出现的 index。

### 代码
```csharp
public class Solution
{
    public char FirstUniqChar(string s)
    {
        // 执行用时: 200 ms, 在所有 C# 提交中击败了 7.84% 的用户
        // 内存消耗: 34.6 MB, 在所有 C# 提交中击败了 100.00% 的用户

        Dictionary<char, (int, int)> freqDictionary = new Dictionary<char, (int, int)>();
        for (int i = 0; i < s.Length; i++)
        {
            char currentChar = s[i];
            if (freqDictionary.ContainsKey(currentChar))
            {
                (int, int) charInfo = freqDictionary[currentChar];
                freqDictionary[currentChar] = (charInfo.Item1 + 1, charInfo.Item2);
            }
            else
            {
                freqDictionary[currentChar] = (1, i);
            }
        }

        try
        {
            return freqDictionary?.Where(charFreqInfo => charFreqInfo.Value.Item1 == 1)
                                ?.OrderBy(charFreqInfo => charFreqInfo.Value.Item2)
                                ?.Select(charFreqInfo => charFreqInfo.Key)
                                ?.First() ?? ' ';
        }
        catch
        {
            return ' ';
        }
    }
}
```