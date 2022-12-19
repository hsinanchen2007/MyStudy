### 思路

**暴力**

```
两行 for 循环暴力一下就过了。
```

**时间复杂度:** O(n^2)
**空间复杂度:** O(n)

##### Python3代码

```python
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = []
        for i in range(n):
            cnt = 0
            for j in range(n):
                if nums[j] < nums[i]:
                    cnt += 1
            ans.append(cnt)
        return ans
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1365-How-Many-Numbers-Are-Smaller-Than-the-Current-Number/1365.py)