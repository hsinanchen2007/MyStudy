执行用时 : 116 ms, 在所有 C# 提交中击败了98.68%的用户
内存消耗 : 22.6 MB, 在所有 C# 提交中击败了99.09%的用户
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        List<char> ls = new List<char>();
        int n = s.Length;
        int intMaxLength = 0;
        for (int i = 0; i < n; i++)
        {
            if (ls.Contains(s[i]))
            {
                ls.RemoveRange(0, ls.IndexOf(s[i]) + 1);
            }
            ls.Add(s[i]);
            intMaxLength = ls.Count > intMaxLength ? ls.Count : intMaxLength;
        }
        return intMaxLength;
    }
}
