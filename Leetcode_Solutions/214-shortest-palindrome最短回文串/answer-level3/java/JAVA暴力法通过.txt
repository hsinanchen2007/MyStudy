```
    private static boolean isPalindrone(String s, int i) {
        for (int j = 0, k = i; j < k; j++, k--) {
            if (s.charAt(j) != s.charAt(k)) {
                return false;
            }
        }
        return true;
    }
    public static String shortestPalindrome(String s) {
       int i = 0;
       for (i = s.length() - 1; i >= 0; i--) {
           if (isPalindrone(s, i)) {
               break;
           }
       }       
       return (new StringBuffer(s.substring(i + 1)).reverse()).toString() + s;
    }
```
