```java
class Solution {
    public int findComplement(int num) {
        int i = 0x7fffffff;
        while (i >= num) {
            i >>>= 1;
        }
        return (i << 1) ^ num ^ 1;
    }
}
```