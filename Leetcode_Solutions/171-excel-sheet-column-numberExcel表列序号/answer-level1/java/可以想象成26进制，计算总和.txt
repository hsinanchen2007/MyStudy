### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int titleToNumber(String s) {
        if (s.length() == 0) return 0;
        int ret = 0, d = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            ret += (s.charAt(i) - 'A' + 1) * d;
            d *= 26;
        }
        return ret;
    }
}
```