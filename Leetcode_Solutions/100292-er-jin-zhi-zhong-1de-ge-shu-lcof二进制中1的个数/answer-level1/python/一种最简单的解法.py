一起组队刷题，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
如果n!=0，n的二进制中至少有一个1

- 如果1在最低位，n-1 & n得到的数正好将这个1，变成0
- 如果1不在最低位，n-1 & n得到的数正好将这个1，变成0

因此我们判断n-1 & n能够循环运行的次数就可以判断二进制中有多少个1了。

在python中需要使用c_int()函数不然负数不会变成0.


### 代码

```python
from ctypes import *
class Solution(object):
    def hammingWeight(self, n):
        cnt = 0
        while c_int(n).value:
            n = n & (n-1)
            cnt += 1
        return cnt

```