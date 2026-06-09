### 解法1：迭代法
想法很简单，就是一直除以 $2$

代码如下：
```Python [-Python]
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n<=0: return False
        while n>1:
            if n%2 == 0:
                n //= 2
            else:
                return False
        return True 
```

### 解法2：位运算
1. 如果是 $2$ 的幂，则二进制应该只有最高位上是 $1$，其他都是 $0$；
2. 基于上面的结论，`n-1` 应该除了最高位是 $0$（与 $n$最高位对应的位置），其他都是 $1$；
3. 因此，`n&(n-1)` 应该等于 $0$。

代码如下：
```Python [-Python]
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and  n & (n - 1)==0

```
### 解法3：降底法
所谓降底，就是逐步降底数的大小，我觉得这种方法对于比较大的数会高效一点

代码如下：

```Python [-Python]
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n<=0:return False
        nums = [1,2,4,8]   # 候选底
        i = 3      #先从最大的底开始
        while n>8:
            while n%nums[i] != 0: # 逐步降底
                i -= 1
            if i==0:
                return False
            n //= nums[i]
        return n in nums
            
```
