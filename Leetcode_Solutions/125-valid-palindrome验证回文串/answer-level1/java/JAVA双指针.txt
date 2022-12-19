```
class Solution {
    public boolean isPalindrome(String s) {
        
        if (s.length() == 0)
            return true;
        
        String low = s.toLowerCase();
        
        int i = 0;
        int j = low.length() - 1;

        while (i < j)
        {
            if (!Character.isLetterOrDigit(low.charAt(i)))
            {
                i++;
                continue;
            }
            if (!Character.isLetterOrDigit(low.charAt(j)))
            {
                j--;
                continue;
            }
            if (low.charAt(i) != low.charAt(j))
                return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
}
```
