### 解题思路
JAVA 暴力循环就完事了

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
          //先把特殊情况写了
        if ("".equals(needle)) return 0;
        if ("".equals(haystack)) return -1;
        int h_length = haystack.toCharArray().length;
        int n_length = needle.toCharArray().length;
        if (h_length < n_length) return -1;

        //匹配逻辑
        for (int i = 0; i < h_length; i++) {
            if (haystack.charAt(i) == needle.charAt(0)) {//如果匹配到跟neddle开头相同的字符，则进行判断
                if (n_length + i > h_length) {//超出haystack的长度，无匹配
                    return -1;
                }
                boolean flag = false;
                for (int j = 0; j < n_length; j++) {
                    if (haystack.charAt(i + j) != needle.charAt(j)) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    continue;
                } else {
                    return i;
                }
            }
        }
        return -1;

    }
}
```