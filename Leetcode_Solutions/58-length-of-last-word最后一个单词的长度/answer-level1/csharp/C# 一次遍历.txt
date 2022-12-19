```
public class Solution {
    public int LengthOfLastWord(string s) {
        int lastCount = 0;
        int count = 0;
        for (int i = 0; i < s.Length; i++)
        {
            var _char = s[i];
            if (_char == ' ')
            {
                count = 0;
                continue;
            }

            count++;
            lastCount = count;
        }

        return lastCount;
    }
}
```
