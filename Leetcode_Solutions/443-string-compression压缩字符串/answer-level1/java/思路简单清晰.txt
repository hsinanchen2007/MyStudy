### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int compress(char[] chars) {
        StringBuffer s = new StringBuffer();
        for (int i = 0; i < chars.length; i++) {
            int count = 1;
            while (i < chars.length - 1 && chars[i] == chars[i + 1]) {
                count++;
                i++;
            }
            if (count == 1) {
                s.append(chars[i]);
            } else {
                s.append(chars[i]).append(count);
            }
        }
        for (int i = 0; i < s.length(); i++) {
            chars[i] = s.charAt(i);
        }
        return s.length();
    }
}
```