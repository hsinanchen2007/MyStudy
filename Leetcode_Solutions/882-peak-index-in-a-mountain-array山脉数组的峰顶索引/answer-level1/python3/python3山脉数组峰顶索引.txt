### 解题思路二分法求解

### 代码

```python3
class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        left=0
        right=len(A)-1
        while right-left>1:
            mid=left+(right-left)//2
            if A[mid]>A[mid-1]:
                left=mid
            else:
                right=mid
        return left
```

![image.png](https://pic.leetcode-cn.com/5914f59c179e04e4fbe34b9465fbae2cb6470c3fbadf8628aa1b9dfe064b8b25-image.png)
