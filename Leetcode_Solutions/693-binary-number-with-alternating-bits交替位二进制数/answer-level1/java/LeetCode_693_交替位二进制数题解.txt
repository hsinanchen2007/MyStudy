### 代码

```java
class Solution {
    public boolean hasAlternatingBits(int n) {
        while (n != 0) {
            int last = n & 1;
            n = n >> 1;
            int cur = n & 1;
            if (last == cur) {
                return false;
            }
        }
        return true;
    }
}
```