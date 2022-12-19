### 思路解析
既然丑数只能被 2、3、5 整除，那么一个数`num`是丑数，则需要满足下面的条件：

$$
num = 2^i3^j5^k
$$

当 2、3、5 是`num`的倍数的话，那么我就用 2、3、5 不停的去除以`num`，如果除完 2、3、5 之后，最后的结果是`1`，则说明能够除尽，它是一个丑数；否则如果最后的结果不是`1`，则说明`num`还有其他的因子，就不是丑数。

需要注意的是：`0`不是丑数，而`1`是丑数（题目规定）。


### 代码
```java
class Solution {
    public boolean isUgly(int num) {
        if (num == 0) {
            return false;
        }
        
        int[] factors = {2, 3, 5};
        for (int factor : factors) {
            // 能进入 while 说明，当前的 factor 是 num 的倍数
            while (num % factor == 0) {
            // 我就不停的用 2、3、5 去除 num
            // 2 除完了用 3 除，3 除完了用 5 除
                num /= factor;
            }
        }
        return num == 1;
    }
}
```

### 全部题解
《剑指Offer》的全部题解与 LeetCode 的部分题解在此下方，其中还包含**基础算法**与**进阶算法**，欢迎查看~
[LeetCode、SwordToOffer and other algorithms in Java.](https://github.com/dyfloveslife/LeetCodeAndSwordToOffer)