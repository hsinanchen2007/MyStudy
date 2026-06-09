```
class Solution {
    public int titleToNumber(String s) {
        int n = s.length()-1;
        int result = 0;
        while(n>-1){
            char ch = s.charAt(n);
            result += (ch-'A'+1)*Double.valueOf(Math.pow(26,s.length()-1-n)).intValue();    
            n--;
        }
        return result;
    }
}
```
