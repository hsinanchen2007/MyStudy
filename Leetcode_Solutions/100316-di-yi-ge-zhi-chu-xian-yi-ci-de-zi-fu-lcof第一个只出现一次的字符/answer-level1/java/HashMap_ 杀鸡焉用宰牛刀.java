### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        if(s == null || s.length() == 0) return ' ';
        char[] dict = new char[256];
        char[] array = s.toCharArray();
        for (char c : array) {
            dict[c - '0']++;
        }

        for(char c : array) {
            if(dict[c - '0'] == 1) {
                return c;
            }
        }
        return ' ';
    }
}
```