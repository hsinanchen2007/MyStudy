### 解题思路
![1.png](https://pic.leetcode-cn.com/63ff048616ea33233a11967e6beb3ecdfe4e1846ec5ed0879fb0cf6edb37eaf1-1.png)
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        right = num//2
        left = 1
        if num == 1:
            return True
        while left<=right:
            mid = left + (right-left)//2
            sqr = mid**2
            if sqr==num:
                return True
            elif sqr<num:
                left = mid+1
            else:
                right = mid-1
        return False
```