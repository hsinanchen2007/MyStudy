在2的幂次方数中判断除数是3时，是否余数为1，若是，则为4的幂，否则不是。
```
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num&(num-1)!=0:
            return False
        return num%3==1
```
![image.png](https://pic.leetcode-cn.com/076ae23ab194cc0a151ebb834ab61b41fc084304571e98a6de7ff8d525ba2c99-image.png)
