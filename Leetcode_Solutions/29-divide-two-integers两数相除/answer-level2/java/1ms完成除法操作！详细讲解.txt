这道题其实可以很容易联想到我们经常用到的十进制的除法，这里有一个例子来说明如何把十进制除法的思想套用在二进制上面。

![1.png](https://pic.leetcode-cn.com/07d4f60fa9c35b12a739c0694337d6700f9b3c57511e211f4e11e67a35b3fdf1-1.png)


图片是用`33`除以`6`，对应二进制`100001`除以`110`，有三步：

1. 将被除数从`110`开始向左移位右侧补`0`，直到找到最大的比`100001`小的数字`11000`（图中右侧的`0`已经被省略掉了），这个时候向左移动了两位也就是乘以`100`，余数是`1000`
2. 再将`110`向左移动到最大的比`1000`小数字，这个时候就是本身，相当于乘以`1`（向左移动了`0`位），余数是`11`
3. 因为余数已经比被除数`110`要小了，这个时候可以直接停止运算，将上面两个步骤计算得到的**乘数**加起来就是我们最后的结果了。

这里我们就用简单的java代码来实现一下这个逻辑：

```java
public int divide(int dividendInt, int divisorInt) {
    int shiftedDivisor;                   // 移位后的除数
    int quotient = 0;                     // 记录除法得到的商
    int remainder = dividendInt;

    while (remainder>=divisorInt) {
        int tempQuotient = 1;             // 临时的商
        dividendInt = remainder;          // 处理上一轮的余数
        shiftedDivisor = divisorInt;      // 重置被除数
        while (dividendInt>=shiftedDivisor) {
            shiftedDivisor <<=1;
            tempQuotient <<= 1;
        }
        quotient += tempQuotient >> 1;    // 累加计算得到的商
        remainder = dividendInt - (shiftedDivisor >> 1); // 位移优先级比减号低，要用括号
    }
    return quotient;
}
```

通过循环的方法得到了我们要的除法的实现逻辑，但是这个方法只是对除数和被除数都是**正数**才起作用，比如除数是`-100`被除数是`10`或者`-10`的时候，返回的结果是`0`！对于`-100`除以`-10`这个例子，在比较余数和移位的除数的大小的时候，如果都是正数，余数比除数小的时候停止循环是正常的，但是在都是负数的时候，这样做就有问题了，余数比除数大，商才是`0`，所以上面两个循环的终止条件的不等号方向换一下就可以了。

```java
public int divide(int dividendInt, int divisorInt) {
    int shiftedDivisor;
    int quotient = 0;
    int remainder = dividendInt;

    while (remainder<=divisorInt) {           // 注意 变成了小于等于
        int tempQuotient = 1;
        dividendInt = remainder;
        shiftedDivisor = divisorInt;
        while (dividendInt<=shiftedDivisor) {  // 注意 变成了小于等于
            shiftedDivisor <<=1;
            tempQuotient <<= 1;
        }
        quotient += tempQuotient >> 1;
        remainder = dividendInt - (shiftedDivisor >> 1);
    }
    return quotient;
}
```

现在我们都是正数和都是负数的情况都有了，一个正数一个负数咋办呢？那就把符号变一下，变成一样的，最后在返回结果的时候变回来。这里题目善意的提醒了一下要考虑边界问题，在考虑转换符号的时候需要考虑到`-2147483648`这个值的特殊性，也就是负数变正数要小心，但是正数变成负数可以随意，那就不如直接负数运算得了（参考这篇[文章](https://leetcode-cn.com/problems/divide-two-integers/solution/zhi-xing-shi-jian-1msji-bai-100-by-luca-zhao/)）。在累加每一次除法得到的商的时候，也是使用负数`-1`的移位来避免溢出问题（比如`-2147483648`除以`1`带来的溢出问题）。

在对除数进行移位的时候，还需要注意一下移位之后除数不能溢出，能够使用的最好方法就是在移位之前判断一下除数是否是小于最小数字的一半（如果是用正数移位的话，就应该是判断是否是大于最大数字的一半），如果小于，下一次移位一定就会溢出，这个时候就只能直接终止循环。

在判断结果的符号的时候用一下位运算的小技巧，在上面讲到异或操作的时候，如果是相同的就返回`0`，否则是`1`，所以对两个数字最高位进行异或操作，如果是`0`就代表结果是正号，反之就是负号。除此之外还有一个极端情况，当被除数取最小值`-2147483648`并且除数取`-1`的时候，得到的结果是`2147483648`会溢出，因为只有这样的一个特例，可以直接排除，对于剩下的其他的数字不管怎样都不会溢出，整理之后的代码如下：

```java
public int divide(int dividendInt, int divisorInt) {
    if (dividendInt == Integer.MIN_VALUE && divisorInt == -1) {
        return Integer.MAX_VALUE;         // 对于极端情况，直接排除，返回int最大值
    }
    boolean negSig =
            ((dividendInt ^ divisorInt) & Integer.MIN_VALUE) == Integer.MIN_VALUE;  // 判断结果是否是负数

    dividendInt = dividendInt > 0 ? -dividendInt : dividendInt;                     // 被除数取负值
    divisorInt = divisorInt > 0 ? -divisorInt : divisorInt;                         // 除数取负值

    int shiftedDivisor;                   // 移位后的除数
    int quotient = 0;                     // 记录除法得到的商
    int remainder = dividendInt;
    int minShiftDivisor = Integer.MIN_VALUE >> 1; // 防止溢出，大于这个值之后不能再向左移位了

    while (remainder<=divisorInt) {
        int tempQuotient = -1;             // 临时的商，全部用负数处理
        dividendInt = remainder;           // 处理上一轮的余数
        shiftedDivisor = divisorInt;       // 重置被除数
        while (dividendInt<=(shiftedDivisor<<1)          // 比被除数小才进行接下来的计算
                && shiftedDivisor >= minShiftDivisor) {  // 判断是否移位后会溢出
            shiftedDivisor <<=1;
            tempQuotient <<= 1;
        }
        quotient += tempQuotient;                        // 累加计算得到的商
        remainder = dividendInt - shiftedDivisor;        // 得到余数，下一轮作为新的被除数
    }

    return negSig?quotient:-quotient;     // 如果是负数就直接返回结果，如果不是就变换成正数
}
```
更多内容请看我的[**个人博客**](http://sunshuyi.vip)