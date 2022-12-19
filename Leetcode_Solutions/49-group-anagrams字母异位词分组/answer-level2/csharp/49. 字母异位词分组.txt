### 解题思路
统计词频，使用词频分组‘’

### 代码

```csharp
public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        var result = new Dictionary<string, IList<string>>();
        foreach (var word in strs)
        {
            var map = GetWordMap(word);
            if (result.ContainsKey(map))
            {
                result[map].Add(word);
            }
            else
            {
                result[map] = new List<string>() { word };
            }
        }

        return result.Values.ToList();
    }

    public string GetWordMap(string word)
    {
        var map = new int[26];
        foreach (var @char in word)
        {
            map[@char - 'a']++;
        }
        return string.Join(",", map);
    }
}
```