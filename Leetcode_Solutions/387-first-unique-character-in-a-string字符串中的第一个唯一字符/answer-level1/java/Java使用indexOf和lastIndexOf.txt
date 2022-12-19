直接使用 java String相关的函数，判断字符只存在一次，上代码
``` java
class Solution {
    public int firstUniqChar(String s) {
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (s.lastIndexOf(chars[i]) == s.indexOf(chars[i])) {
                return i;
            }
        }
        return -1;
    }
}
```
