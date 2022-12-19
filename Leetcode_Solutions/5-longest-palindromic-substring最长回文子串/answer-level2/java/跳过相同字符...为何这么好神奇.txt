- 代码重构自外站
```java
public String longestPalindrome(String s) {
    char[] arr = s.toCharArray();
    int len = arr.length, begin = 0, maxLen = 1;
    if (len < 2) return s;
    for (int i = 0; i < len; i++) {
        int l = i - 1, r = i;
        // 跳过相同字符(必回文)
        while (r + 1 < len && arr[r] == arr[r + 1]) r++;
        i = r++; // 下一个i直接从相同字符的下一个开始遍历
        // 中心扩展
        while (l >= 0 && r < len && arr[l] == arr[r]) {
            l--;
            r++;
        }
        // 记录最值
        if (r - l - 1 > maxLen) {
            maxLen = r - l - 1;
            begin = l + 1;
        }
    }
    return s.substring(begin, begin + maxLen);
}
```
