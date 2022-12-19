### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int CountCharacters(string[] words, string chars) {
        int[] chars_count = count(chars);
            int c = 0;
            foreach (var item in words)
            {
                int[] word_count = count(item);
                if (contains(chars_count, word_count))
                {
                    c += item.Length;
                }
            }
            return c;
    }
      public static bool contains(int[] chars_count,int[] words_count)
        {
            for (int i = 0; i < 26; i++)
            {
                if (chars_count[i] < words_count[i])
                {
                    return false;
                }
            }
            return true;
        }
       public static int[] count(String word)
        {
            int[] counter = new int[26];
            for (int i = 0; i <word.Length; i++)
            {
                char c = word[i];
                counter[c - 'a']++;
            }
            return counter;
        }
}
```