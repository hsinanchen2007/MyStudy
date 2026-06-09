### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int MinimumLengthEncoding(string[] words) {
        for(int i = 0; i < words.Length; i++){
            var word = words[i].ToCharArray();
            Array.Reverse(word);
            words[i] = new string(word);
        }
        Array.Sort(words);
        int res = 0;
        for(int i = 1; i < words.Length; i++){
            if (words[i].IndexOf(words[i - 1]) == -1)
                res += words[i - 1].Length + 1;
        }
        res += words.Last().Length + 1;
        return res;
    }
}
```