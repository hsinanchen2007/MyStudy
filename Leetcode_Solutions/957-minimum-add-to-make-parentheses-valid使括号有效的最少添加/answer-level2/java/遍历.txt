```
class Solution {
    public int minAddToMakeValid(String S) {
        char[] arr = S.toCharArray();
        int res = 0;
        int l = 0, r = 0;
        for (char a : arr) {
            if (a == '(') {
                ++l;
            } else {
                --l;
                if (l < 0) {
                    l = 0;
                    ++res;
                }
            }
        }
        return res + l;
    }
}
```