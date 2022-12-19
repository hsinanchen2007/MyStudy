思路如下，**滑动窗口+数组**
**记录当前最长字符串，同时窗口向右移动，无论何时都使得当前窗口含有当前最长不重复子串，知道窗口移到底部。返回最大长度。**
注：**有个地方取了巧，在遍历字符串的时候将遍历过的字符记录在自定义长度为95的数组里(与ASCII码表相对应)。**
```
public static int lengthOfLongestSubstring(String s) {
    char[] str = s.toCharArray();
    int[] exist = new int[127];
    int i1 = 0;
    int result = 0;
    int i2 = 0;
    for (; i2 < str.length; ++i2) {
        if (exist[str[i2]] >= i1 + 1) {
            result = i2 - i1 > result ? i2 - i1 : result;
            i1 = exist[str[i2]];
        }
        exist[str[i2]] = i2 + 1;
    }
    return i2 - i1 > result ? i2 - i1 : result;
}
```
