- 考虑到越界的问题，使用long

```java 
class Solution {
    public int arrangeCoins(int n) {
        long m = n;
        return (int) (-0.5 + Math.sqrt(0.25 + 2 * m));
    }
}
```