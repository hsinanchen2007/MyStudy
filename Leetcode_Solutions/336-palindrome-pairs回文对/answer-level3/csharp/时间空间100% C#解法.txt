将所有字符串储存到Dictionnary中，对每个字符串，讨论四种情况:
1. 若该字符串为回文字符串且字典里有空字符串，添加两次（一正一反）
2. 若该字符串不为回文字符串且字典里有该字符串的反转，添加
3. 如果某个字符串能找到一个分割点，分割点前的部分是回文，后半部分翻转后也在数组里，添加
4. 如果某个字符串后部分是回文，前半部分翻转后在数组里，添加
```
public class Solution {
    public IList<IList<int>> PalindromePairs(string[] words)
    {
        IList<IList<int>> res = new List<IList<int>>();
        if (words.Length <= 1)
        {
            return res;
        }
        Dictionary<string, int> dict = new Dictionary<string, int>();
        for (int i = 0; i < words.Length; ++i)
        {
            dict.Add(words[i], i);
        }
        for (int index = 0; index < words.Length; ++index)
        {
            string word = words[index];
            if (string.IsNullOrEmpty(word))
            {
                continue;
            }

            bool isPalindrome = IsPalindrome(word);
            if (isPalindrome && dict.ContainsKey(string.Empty))
            {
                res.Add(new List<int>(new int[] { index, dict[string.Empty] }));
                res.Add(new List<int>(new int[] { dict[string.Empty], index }));
            }
            if (!isPalindrome && dict.ContainsKey(Reverse(word)))
            {
                res.Add(new List<int>(new int[] { index, dict[Reverse(word)] }));
            }
            for (int i = 1; i < word.Length; ++i)
            {
                string wordLeft = word.Substring(0, i);
                string wordRight = word.Substring(i);
                if (IsPalindrome(wordLeft) && dict.ContainsKey(Reverse(wordRight)))
                {
                    res.Add(new List<int>(new int[] { dict[Reverse(wordRight)], index }));
                }
                if (IsPalindrome(wordRight) && dict.ContainsKey(Reverse(wordLeft)))
                {
                    res.Add(new List<int>(new int[] { index, dict[Reverse(wordLeft)] }));
                }
            }
        }
        return res;
    }

    private bool IsPalindrome(string word)
    {
        if (string.IsNullOrEmpty(word))
        {
            return true;
        }
        for (int i = 0; i < word.Length / 2; ++i)
        {
            if (word[i] != word[word.Length - 1 - i])
            {
                return false;
            }
        }
        return true;
    }

    private string Reverse(string word)
    {
        if (string.IsNullOrEmpty(word))
        {
            return string.Empty;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = word.Length - 1; i >= 0; --i)
        {
            sb.Append(word[i]);
        }
        return sb.ToString();
    }
}
```
