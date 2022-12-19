**思路**
求两数异或之后二进制中1的个数即可。
```java
    public int convertInteger(int a, int b) {
        return Integer.bitCount(a ^ b);
    }
```