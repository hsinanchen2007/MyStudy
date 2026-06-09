### 解题思路
二分查找

### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num==1 or num==4:
            return True
        left=1
        right = num//2
        mid=(right+left)//2
        while left<=right:
            if mid**2>num:
                right=mid-1
                mid=(right+left)//2
            elif mid**2==num:
                return True
            else:
                left = mid+1
                mid=(right+left)//2
        return False
```

![image.png](https://pic.leetcode-cn.com/9d0766b32bd32cea66d39118703176082b3ed8183ad1613928ea7f741fdaba38-image.png)
