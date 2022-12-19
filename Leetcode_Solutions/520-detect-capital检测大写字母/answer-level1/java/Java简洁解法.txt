```
class Solution {
    public boolean detectCapitalUse(String word) {
        
       
        char[] chars = word.toCharArray();
        int upper = 0;//大写字母个数
        int lower = 0;//小写字母个数
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] - 'a' < 0)
                upper++;
            else 
               lower++; 
        }
        
        if (upper == chars.length || lower == chars.length || (upper == 1 && chars[0] < 'a'))
            return true;
        else 
            return false;
    }
}
```