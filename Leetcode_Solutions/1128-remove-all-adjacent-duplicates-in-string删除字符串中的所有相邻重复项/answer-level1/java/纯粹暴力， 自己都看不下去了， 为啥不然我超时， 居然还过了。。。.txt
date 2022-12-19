暴力迭代， 自己都看不下去了， 为啥不然我超时， 居然还过了。。。

```
class Solution {
    public String removeDuplicates(String S) {
        String ss = remove(S);
        while (ss != remove(ss)) {
            ss = remove(ss);
        }
        return ss;
    }

    private static String remove(String s) {
        String cc = "";
        for (int i=0; i<s.length()-1; i++) {
            if (s.charAt(i) == s.charAt(i+1)) {
                cc = s.substring(0, i) + s.substring(i+2);
                return cc;
            }
        }
        return s;
    }
}
```