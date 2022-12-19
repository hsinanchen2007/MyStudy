### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int reverse(int x) {
                int res;
        Long b = Long.valueOf(0);
        while (x != 0) {
            res = x % 10;
            x = x / 10;
            b = b * 10 + res;
        }

        if (b > Integer.MAX_VALUE || b < Integer.MIN_VALUE) {
            return 0;
        }
        return Integer.valueOf(String.valueOf(b));
    }
    
}
```