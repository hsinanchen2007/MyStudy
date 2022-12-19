### 解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        if (s == null || s.length() == 0) {
            return s;
        }
        String sAfterTrim = s.trim();
        int len = sAfterTrim.length();
        sAfterTrim += " !";
        StringBuilder stringBuilder = new StringBuilder();
        // 双指针, 降低时间复杂度, 避免用正则
        int first = 0;
        for (int last = 0; last <= len; last++) {
            char c = sAfterTrim.charAt(last);
            if (c == 32 && sAfterTrim.charAt(last + 1) != 32) {
                stringBuilder.insert(0, sAfterTrim.substring(first, last).trim() + " ");
                first = last + 1;
            }
        }
        return stringBuilder.toString().trim();
    }
}
```