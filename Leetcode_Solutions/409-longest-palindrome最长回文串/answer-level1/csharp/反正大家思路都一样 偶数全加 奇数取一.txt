### 解题思路
记录所有字母的数量 然后 偶数的全加上  如果有奇数的只能用上一个 所有奇数全按偶数加上 最后+1 

### 代码

```csharp
public class Solution {
    public int LongestPalindrome(string s) {
        Dictionary<char, int> letters = new Dictionary<char, int>();
        for(int i = 0; i < s.Length; i ++)
        {
            if(letters.ContainsKey(s[i]))
                letters[s[i]]++;
            else
                letters.Add(s[i], 1);
        }

        int count = 0;
        bool isExitLowercase = false;
        foreach(var item in letters)
        {
            if((item.Value & 1) == 0) count+=item.Value;
            else
            {
                count+=item.Value - 1;
                isExitLowercase = true;
            }
        }
        return isExitLowercase ? count + 1 : count;
    }
}
```