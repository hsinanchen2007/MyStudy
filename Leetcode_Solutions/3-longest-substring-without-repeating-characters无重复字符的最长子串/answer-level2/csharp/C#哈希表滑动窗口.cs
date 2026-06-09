
```
public class Solution {
    public int LengthOfLongestSubstring(string s) {
      int i=0;
      int j=0;
      int len=0;
      HashSet<char> hs=new HashSet<char>(); 
      while(j<s.Length)
      {
        if(hs.Contains(s[j]))
        {
            hs.Remove(s[i]);
            i++;
        }
        else
        {
            hs.Add(s[j]);
            len=Math.Max(len,hs.Count);
            j++;
        }
      }
      return len;
    }
}
```



执行用时 :
108 ms
, 在所有 C# 提交中击败了53.91%的用户
内存消耗 :
25.6 MB, 在所有 C# 提交中击败了5.89%的用户