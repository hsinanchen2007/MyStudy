**执行用时：5 ms
       内存消耗：37.8 MB**
```
代码块
class Solution {
    //双指针思想
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0 || haystack.equals(needle)) return 0;
        int i = 0, j = 0;
        while (i < haystack.length()) {
            if (haystack.charAt(i++) == needle.charAt(j)) {
                j++;
            } else {
                if (j > 0) {
                    i = i - j ;
                    j = 0;
                }
            }
            if (j == needle.length()) {
                return i - j;
            }
        }
        return -1;

    }
}
```
