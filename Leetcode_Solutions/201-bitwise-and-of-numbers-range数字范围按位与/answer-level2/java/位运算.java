### 解题思路
很巧妙的做法

### 代码

```java
class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        int zero = 0;
        while (m < n) {
            zero++;
            m = m >>> 1;
            n = n >>> 1;
        }
        return m << zero;
    }
}
```