不快不慢，好理解~
```
class Solution {
    
    private boolean check(String s, int i, int j) {
        String str = s.substring(0, i);
        StringBuilder sb = new StringBuilder();
        for(int index = 0; index < j; index++) {
            sb.append(str);
        }
        
        return s.equals(sb.toString());
    }
    
    public boolean repeatedSubstringPattern(String s) {
        int len = s.length();
        if(len == 1) {
            return false;
        }

        for(int i = 1; i <= len/2; i++) {
            if (len % i == 0 && check(s, i, len / i)) {
                return true;
            }
        }
        
        return false;
    }
}
```
