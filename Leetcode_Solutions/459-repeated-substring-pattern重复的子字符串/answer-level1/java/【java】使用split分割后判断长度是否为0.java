```
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        if(s.length() == 1) {
            return false;
        }
        int n = s.length() / 2;
        for (int i=1;i<=n;i++) {
            String sub = s.substring(0,i);
            if (s.length() % i == 0 ) {
                int len = s.split(sub).length;
                 if (len == 0) {
                   return true;
                }
            }      
        }
        return false;
    }
}
```
