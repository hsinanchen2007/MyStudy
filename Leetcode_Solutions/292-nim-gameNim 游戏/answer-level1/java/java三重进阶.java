### 1、典型错误思路

尝试用递归去解决， 每次先手可以选择1、2、3种选择。可是不论用且或者与判断，都违背了每一步要最优解的贪心算法原则，因为每一步不止一个解。

代码：

```java
boolean nim=true;

public boolean canWinNim(int n) {
    if (n<=3) {
        return nim;
    }
    nim = nim?false:true;
    return canWinNim(n-1)&&canWinNim(n-2)&&canWinNim(n-3);
}
```

### 2、官方解答

当你面对1-3块石头的时候，你作为先手是赢的。当你面对4块石头，你一定会输。

再往后推演，5-7块你会赢，8块石头你一定会输。N=4、8、12、16。。。

面对4的整数倍的人永远无法翻身，你拿N根对手就会拿4-N根，保证每回合共减4根，你永远对面4倍数，直到4. 相反，如果最开始不是4倍数，你可以拿掉刚好剩下4倍数根，让他永远对面4倍数。

代码：

```java
public boolean canWinNim(int n) {
    return n%4 !=0;
}
```

### 3、官解进阶

使用Java位运算:

4的二进制 0100

3的二进制 0011

如果n除4没有余数的话，那二进制n的最右边两位一定为0，&的结果也就是0。

在二进制的世界，应该没有比位运算快的了。

代码：

```java
public boolean canWinNim(int n) {
    return (n&3)!=0;
}
```

