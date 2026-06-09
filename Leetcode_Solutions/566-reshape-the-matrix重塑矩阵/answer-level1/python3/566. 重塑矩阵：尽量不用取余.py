![image.png](https://pic.leetcode-cn.com/6bd66732babb5cfa5d8ebae752c8ca9b21cc6db378fc30d0239aadb439efa790-image.png)

模拟题，取余效率相对较低，这种题里能不用则不用。

```python []
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        if len(nums) * len(nums[0]) != r * c:
            return nums
        ans=[[0] * c for _ in range(r)]
        i, j = 0, 0
        for line in nums:
            for num in line:
                ans[i][j] = num
                j += 1
                if j == c:
                    j = 0
                    i += 1
        return ans
```

或者直接这样写：


```python []
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        if len(nums) * len(nums[0]) != r * c:
            return nums
        ans=[[0] * c for _ in range(r)]
        i, j = 0, 0
        for num in itertools.chain(*nums):
            ans[i][j] = num
            j += 1
            if j == c:
                j = 0
                i += 1
        return ans
```