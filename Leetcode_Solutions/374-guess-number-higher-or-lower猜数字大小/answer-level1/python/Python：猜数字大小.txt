### 解题思路
题目比较费解，读懂以后还是挺简单的，就是标准二分查找

### 代码

```python3
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        l,r=1,n
        while l<r:
            m=(l+r)//2
            res=guess(m)
            if res==-1:r=m-1
            if res==1:l=m+1
            if res==0:return m
        return l
```