### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int MinimumLengthEncoding(string[] words) {
         HashSet<string> set = new HashSet<string>(words);
            for (int i = 0; i < words.Length; i++)
            {
                for (int j = 1; j < words[i].Length; j++)
                {
                    set.Remove(words[i].Substring(j));
                }
            }
            int res = 0;
            foreach (string item in set)
            {
                res += item.Length + 1;
            }
            return res;
    }
}

```