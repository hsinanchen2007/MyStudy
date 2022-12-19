### 解题思路
1.整数反转：这个不用多说，利用取模运算和整除运算的技巧即可。
2.关键在于整数溢出问题，此时我们只要用long类型接收结果，然后输出时判断是否溢出，溢出返回0，否则将long类型的数取整返回。

### 代码

```java
class Solution {
    public int reverse(int x) {
        long cur = 0L;
        int num = x;
        while (num != 0) {
            cur = cur *10 + num%10;
            num = num/10;
        }
        return cur>Integer.MAX_VALUE || cur < Integer.MIN_VALUE?0:(int) cur;
    }
}
```