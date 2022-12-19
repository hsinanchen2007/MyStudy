遍历存入字典 相同字符累加  遍历加上字典值  偶数直接相加count   奇数+count-1

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
            if(item.Value %2 == 0) count+=item.Value;
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