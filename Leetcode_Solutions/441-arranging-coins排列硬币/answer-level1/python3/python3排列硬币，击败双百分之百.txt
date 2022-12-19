```
class Solution:
    def arrangeCoins(self, n: int) -> int:
        if n<2:
            return n
        elif n==2:
            return 1
        elif n<6:
            return 2
        left = 1
        right = n//2+1
        while right-left>1:
            mid = left+(right-left)//2
            if mid*(mid+1)/2>n:
                right=mid
            else:
                left=mid
        return left
```

![image.png](https://pic.leetcode-cn.com/22f80ced2602afc499db5a9a7eb276b65b3325f5c669822f24e40550101a3aa4-image.png)

