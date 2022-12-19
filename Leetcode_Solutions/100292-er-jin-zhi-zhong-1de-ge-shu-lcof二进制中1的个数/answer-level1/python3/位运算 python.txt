- n = i>>1 不改变i的值    i>>=1 i的值变为原来的1/2
- n&(n-1)操作会使得n最右边的1变为0
```
class Solution:
    def hammingWeight(self, n: int) -> int:
        # res = 0
        # if n == 1: return 1
        # # print(n)
        # while n > 0:
        #     res += (n&1)
        #     n >>= 1 #n的值改变   n>>1 n的值没变
        # return res

        res = 0
        while n !=0:
            n = n&(n-1)
            res+=1
        return res
```
