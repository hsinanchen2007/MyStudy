
### 思路

除法的本质就是计算被除数中包含几个除数。如果被除数中包含N个除数，则商就是N。

基于该思路可以很容易的写入如下代码：

```java
// 主要是while 循环的代码
public int divide(int dividend, int divisor) {
  if (dividend == 0) {
    return 0;
  }
  if (dividend == Integer.MIN_VALUE && divisor == -1) {
    return Integer.MAX_VALUE;
  }
  int flag = -1;
  if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
    flag = 1;
  }
  long a = Math.abs((long) dividend);
  long b = Math.abs((long) divisor);
  int res = 0;
  while (a > b) {
    a -= b;
    res++;
  }
  return flag * res;
}
```

该代码在被除数不是很大的时候是没有问题的，但是当被除数增大时，超时是必不可少的。究其原因是因为我们减除数的增长太慢了。那如果我们每次给除数增倍减会不会好一些呢？带着这个疑问我们举个例子看看，计算100 / 3。

**第一轮** 

变化之后的除数是上次的2倍，同理倍数也是2倍。

| 被除数 | 除数 | 被除数减除数           | 倍数 |
| ------ | ---- | ---------------------- | ---- |
| 100    | 3    | 100 - 3 = 97           | 1    |
| 100    | 6    | 100 - 6 = 94           | 2    |
| 100    | 12   | 100 - 12 = 88          | 4    |
| 100    | 24   | 100 - 24 = 76          | 8    |
| 100    | 48   | 100 - 48 = 52          | 16   |
| 100    | 96   | 100 - 96 = 4           | 32   |
| 100    | 192  | 被除数 < 除数 本次结束 |      |

第一轮到除数=96后，我们发现100 - 96 * 2 < 0，所以我们结束这一轮，开启新的一轮。注意：此时我们的被除数已经变成4了。

**第二轮**

| 被除数 | 除数 | 被除数减除数       | 倍数 |
| ------ | ---- | ------------------ | ---- |
| 4      | 3    | 4 - 3 = 1          | 1    |
| 4      | 6    | 被除数 < 除数 结束 |      |

第二轮结束之后被除数为1（即4-3的结果）小于除数，所以计算结束。最终的倍数等于2轮倍数加和（32 + 1 = 33）

### 代码

```java
public int divide(int dividend, int divisor) {
    if (dividend == 0) {
      return 0;
    }
    if (dividend == Integer.MIN_VALUE && divisor == -1) {
      return Integer.MAX_VALUE;
    }
    int flag = -1;
    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
      flag = 1;
    }
    long a = Math.abs((long) dividend);
    long b = Math.abs((long) divisor);
    return flag * getRes(a, b);
  }

  private int getRes(long a, long b) {
    if (a < b) {
      return 0;
    }
    int count = 1;
    long tmp = b;
    while (a > b << 1) {
      b = b << 1;
      count = count << 1;
    }
    return count + getRes(a - b, tmp);
  }
```

### 写在后面

或许有小伙伴会问，那每次增加3倍、4倍可以吗？当时是可以的了，但是这样递归深度会深一些。有兴趣的朋友可以试试