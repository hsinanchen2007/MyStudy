```
public class Solution {
    public int LengthOfLastWord(string s) {
        var arry = s.Split(' ');
        for (int i = arry.Length - 1; i >= 0; i--)
        {
            if (arry[i] == string.Empty)
            {
                continue;
            }

            return arry[i].Length;
        }

        return 0;
    }
}
```
