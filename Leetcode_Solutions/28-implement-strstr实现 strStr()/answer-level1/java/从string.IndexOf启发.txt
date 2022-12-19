### 解题思路
    首先就是要找到needle首字母再haystack出现的地方；
    然后从当前出现首字母位置i出发，用两个下标j和k分别在原字符串和目标字符串中对比；
    如果对比出现不一样，那就再在haystack中找下一个与needle首字母匹配的位置；
    如果匹配完成，则返回当前i的位置；
    如果i已经超出两字符串长度差数，那就不可能匹配的到了，于是返回-1；
    如果needle是空，则返回原字符串首字母位置0；

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
        char[] source = haystack.toCharArray();
        char[] target = needle.toCharArray();
        if (target.length == 0) {
            return 0;
        }
        int max = source.length - target.length;
        char targetFirst = target[0];
        for (int i = 0; i <= max; i++) {
            if (source[i] != targetFirst) {
                while(i++ < max && source[i] != targetFirst);
            }
            if (i <= max) {
                int j = i + 1;
                int end = j + target.length - 1;
                for (int k = 1; j < end && source[j] == target[k]; j++, k++);
                if (j == end) {
                    return i;
                }
            }
        }

        return -1;
    }
}
```