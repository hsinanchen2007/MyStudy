## 思路：
1. 设置两个指针i和j，分别用于指向主串(haystack)和模式串(needle)
2. 从左到右开始一个个字符匹配
  - 如果主串和模式串的两字符相等，则i和j同时后移比较下一个字符
  - 如果主串和模式串的两字符不相等，就跳回去，即模式串向右移动，同时模式串指针归零(i = 1; j = 0)
3. 所有字符匹配结束后，如果模式串指针指到串尾(j = needle.length)，说明完全匹配，此时模式串出现的第一个第一个位置为：i - j


## 代码：
```java []
class Solution {
    public int strStr(String haystack, String needle) {
        char[] hayArr = haystack.toCharArray();
        char[] needArr = needle.toCharArray();
        int i = 0; //主串(haystack)的位置
        int j = 0; //模式串(needle)的位置
        while (i < hayArr.length && j < needArr.length) {
            if (hayArr[i] == needArr[j]) { // 当两个字符相等则比较下一个
                i++;
                j++;
            } else {
                i = i - j + 1; // 一旦不匹配，i后退
                j = 0; // j归零
            }
        }
        if (j == needArr.length) { //说明完全匹配
            return i - j;
        } else {
            return -1;
        }
    }
}
```
