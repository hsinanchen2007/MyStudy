### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int titleToNumber(String s) {
        int result = 0;
        while (s.length() > 0) {
            char cha = 'A';
            int size = s.charAt(0) - cha + 1;
            result += size * Math.pow(26, s.length() - 1);
            s = s.substring(1);
        }
        return result;
    }
}
```