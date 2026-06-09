### 解题思路
二分查找

### 代码

```python3
# The guess API is already defined for you.
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        left=1
        right=n
        mid=n//2+1
        g=guess(mid)
        while g:
            if g==-1:
                right=mid-1
                mid=left+(right-left)//2
                g=guess(mid)
            else:
                left=mid+1
                mid=left+(right-left)//2
                g=guess(mid)
        return mid
```

![image.png](https://pic.leetcode-cn.com/ca63cf4cf2c0b418d6c8d77e6bafcaf6c4978d6bf15e9299a7be3991265c667b-image.png)
