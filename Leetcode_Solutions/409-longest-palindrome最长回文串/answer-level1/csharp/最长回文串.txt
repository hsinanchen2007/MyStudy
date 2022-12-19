
```csharp
public class Solution {
    public int LongestPalindrome(string s) {
        int[] count = new int[128];
        int length = 0;

        foreach(var key in s) 
        {
            if(++count[key] == 2) 
            {
                length += 2;
                count[key] = 0;
            } 
        }
        
        return s.Length > length ? length + 1 : length;
    }
}
```
