利用substring() + equals() 暴力遍历也可以1ms

```
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.equals(""))
            return 0;
        if (haystack.equals(""))
            return -1;
        //避免出界
        int length = haystack.length() - needle.length() + 1;

        for (int i = 0; i < length; i++) {
            if (haystack.charAt(i) == needle.charAt(0)) {
                if (haystack.substring(i, i + needle.length()).equals(needle)) {
                    return i;
                }
            }
        }
        return -1;
    }
}
```
