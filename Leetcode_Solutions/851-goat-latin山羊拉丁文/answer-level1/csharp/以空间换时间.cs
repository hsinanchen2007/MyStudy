### 解题思路
以空间换时间，根据定义的rule，逐步transform word

### 代码

```csharp
public class Solution {
    public string ToGoatLatin(string S) {
        // Get words.
        string[] words = S.Split(" ");
        char[] vowels = {'a', 'e', 'i', 'o', 'u'};

        // Transform words.
        for (int i = 0; i < words.Length; i++) {
            string word = words[i];

            char firstChar = word[0];
            if (vowels.Contains(Char.ToLower(firstChar))) {
                word = $"{word}ma";
            } else {
                string subString = word.Substring(1);
                word = $"{subString}{firstChar}ma";
            }

            word = $"{word}{new String('a', i+1)}";
            words[i] = word;
        }

        return String.Join(" ", words);
    }
}
```