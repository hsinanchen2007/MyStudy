```
class Solution {
    public int lengthOfLastWord(String s) {
        if(s == null || s.length() < 1) return 0;
        String[] ss = s.split(" ");
        return ss.length > 0 ? ss[ss.length-1].length() : 0;
    }
}
```