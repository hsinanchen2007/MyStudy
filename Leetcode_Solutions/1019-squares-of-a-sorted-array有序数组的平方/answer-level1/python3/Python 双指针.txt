### 解题思路
挺简单的一道题，效率一般

### 执行结果
![image.png](https://pic.leetcode-cn.com/7ccf8e48c237532ae99eaa08922dbebec21d2a6a6fbb3069787332777d979f07-image.png)


### 代码

```python3
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        left, right = 0, len(A)-1
        res = []
        while left <= right:
            if A[left]**2 >= A[right]**2:
                res.append(A[left]**2)
                left += 1
            else:
                res.append(A[right]**2)
                right -= 1
        return res[::-1]
```