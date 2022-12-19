```
class Solution {
    public int lengthOfLastWord(String s) {
        if (null == s){
            return 0;
        }
        s = s.trim();
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--){
            if (s.charAt(i) != ' '){
                count++;
            }else{
                break;
            }
        }
        return count;
    }
}
```
