对于该题，使用substring函数，从haystack字符串首位开始遍历，直到找到符合条件的子串即可。

关键在于判断循环的范围以及某些特殊输出情况。

```
class Solution {
    public int strStr(String haystack, String needle) {
        if(needle == null) return 0;
        if(needle.length() > haystack.length()) return -1;
        for(int i = 0;i <= haystack.length() - needle.length();i++)
            if(haystack.substring(i,i + needle.length()).equals(needle) == true)
                return i;
        return -1;
    }
}
```
