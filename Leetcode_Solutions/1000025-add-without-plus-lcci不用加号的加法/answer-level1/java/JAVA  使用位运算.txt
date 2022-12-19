```java
class Solution {
    public int add(int a, int b) {
        int res = 0;
        int xor = a ^ b;
        int forworad = (a & b) << 1;
        return forworad == 0 ? xor : add(xor, forworad);
    }
}
```
