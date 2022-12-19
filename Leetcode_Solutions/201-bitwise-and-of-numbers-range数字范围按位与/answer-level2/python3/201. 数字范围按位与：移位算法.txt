![image.png](https://pic.leetcode-cn.com/9d6538dba57dbbe2d05e370827e3c9dbd7d77bd79ec27ad9f68760b5afd63479-image.png)

考虑范围`[m, n]`，如果`n`比`m`二进制位数高的话，在累计按位与的过程中，数字的每一个二进制位数必然都出现过`0`，所以一旦出现位数不同的情况，结果必然为`0`。

程序中，`m, n`在向右移位的过程中，如果`m, n`相等了，就说明累计按位与的左边肯定等于`m, n`此时的状态，这时候就可以向左移回来了，相当于右边所有位数都补`0`，相等的部分照旧。

如果`m, n`位数不相等，肯定会移到底，两者都为`0`时才会相等停止循环，这时候再向左移多少结果都是`0`。

```python []
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        t = 0
        while m != n:
            m >>= 1
            n >>= 1
            t += 1
        return n << t
```
