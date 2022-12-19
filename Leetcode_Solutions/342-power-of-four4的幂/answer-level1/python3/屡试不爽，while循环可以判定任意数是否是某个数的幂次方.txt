### 解题思路
见代码

### 代码

```python3
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        #判定四的幂次方我就想到2的幂次方 因为4**num == 2**(2*n)
        # #所以无差别
        # from math import sqrt,ceil,floor
        # num =num if num >= 0 else -num
        # if num%4 == 0:
        #     num = math.ceil(math.sqrt(num))
        #     return num > 0 and num&(num-1) == 0
        # else:
        #     return False
        # # num =num if num >= 0 else -num
        # if num == 1:
        #     return True
        # while num > 0:
        #     if num% 4==0:
        #         if num//4 == 1:
        #             return True
        #         num //= num
        #     else:
        #         return False
        if num == 1:
            return True
        while num > 0:
            #不能整除
            if num%4 !=0:
                return False
            #能被整除
            else:
                #判断整除商是否为1
                if num//4 == 1:
                    return True
                #依次循环下去
                num //= 4
```