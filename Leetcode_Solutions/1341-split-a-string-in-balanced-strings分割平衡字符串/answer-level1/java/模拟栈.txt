```
class Solution {
    public int balancedStringSplit(String s) {
        int countR = 0, countL = 0;
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == 'L') countL++;
            else countR++;
            res += countL==countR?1:0;
        }
        return res;
    }
}
```
