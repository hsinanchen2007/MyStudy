### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int titleToNumber(String s) {
        int len = s.length();
        int ret = 0;
        for (int i = 0; i < len; ++i) {
          ret *= 26;  
          int digit = (s.charAt(i) - 'A' + 1);
          ret += digit;
        }
        return ret;

    }
}
```