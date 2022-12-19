```java
public int reverseBits(int n) {
    int res = 0b0; // java 7 以后支持 0b 或 0B 直接写二进制
    for (int i = 0; i < 32; i++) { // 遍历32个位
        res = res << 1; // 结果值先左移
        res = res + n & 1; // |= 或 += 都是一样结果，结果值尾部加上
        n >>>= 1; // 原值无符号右移
    }
    return res;
}
```
```java
public int reverseBits(int n) {
    int res = 0b0, i = 0; // for 换 while
    // res 左移不需要暂存，直接用 (res << 1)
    // | 代替 + ，使得都是位运算
    // n 无需右移后保存，每次重新移也可，故 (n >>> (i - 1))
    while (i++ < 32) res = (res << 1) | (n >>> (i - 1) & 1);
    return res;
}
```
