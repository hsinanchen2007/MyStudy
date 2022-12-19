### 解题思路
先排序，再从后依次遍历。

### 代码

```python3
class Solution:
    def largestPerimeter(self, A: List[int]) -> int:
        A.sort()
        for i in range(len(A)-1,1,-1):
            if A[i]<A[i-1]+A[i-2]:
                return A[i]+A[i-1]+A[i-2]
        return 0
```

![image.png](https://pic.leetcode-cn.com/69e35038c54b67f318e09dad38ec21a5b0896a883f06a4d5beef3eed6c2752f3-image.png)
