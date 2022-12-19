### 解题思路
双百 双重循环

### 代码

```csharp
public class Solution {
    public IList<string> GetValidT9Words(string num, string[] words) {
        var numMap = num.Select(c => c - '0').ToArray();
        var letterMap = new[] { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };
        var result = new List<string>();
        foreach (var word in words)
        {
            var isMatch = true;
            for (int letterIndex = 0; letterIndex < word.Length; letterIndex++)
            {
                var letter = word[letterIndex];
                if (numMap[letterIndex] != letterMap[letter - 'a'])
                {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) result.Add(word);
        }
        return result;
    }
}
```