用常规的方法求给定的数字的因数，这道题限定有四个因数，除去1和数字本身，只要找到一对儿因数就可以。采用的方法是：
- 计算因数，碰到第二对儿直接退出，这个不符合只有四个因数的条件
- 如果这个数是一个素数的平方，那它就只能包含1，这个素数和他本身三个因子，比如 8，9，49等；如果一个数是非素数的平方，那么这个非素数根是可以分解的，所以在计算到这个非素数根之前，一定会找到一对儿因子，当找到这个非素数根时，会因为因子超出4个，自然退出。比如16这个数，首先找到的 2和8这一对儿因子，其次会找到4，这时因为因子数超过四个，直接退出了。
上代码：
```java []
public int sumFourDivisors(int[] nums) {
    int r = 0, num;
    boolean isMatch;
    int[] fs = new int[2];
    for (int i = 0; i < nums.length; i++) {
      num = nums[i];
      // 这里用一个布尔值记录一下是不是找到过因子
      isMatch = false;
      int l = (int) Math.sqrt(num);
      for (int j = 2; j <= l; j++) {
        if (num % j == 0) {
          if (!isMatch) {
            //这里判断是不是一个平方数。其实这个地儿好像只对 2，3起作用。但想法就是这么个想法。
            if(j != num/j) {
              isMatch = true;
              fs[0] = j;
              fs[1] = num / j;
            }
          } else {
            isMatch = false;
            break;
          }
        }
      }

      if (isMatch) {
        r = r + 1 + fs[0] + fs[1] + nums[i];
      }
    }
    return r;
  }
```
有什么问题，欢迎留言讨论。