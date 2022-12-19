**解题思路**：

    若n为2的幂，则n一定能写成1左移一定的位数
    当tmp小于n时尝试移位操作
    若其中有temp==n
    则返回True

```
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n==1:
            return True
        tmp=1
        while n > tmp:
            tmp=tmp<<1
            if tmp==n:
                return True
        return False
```
