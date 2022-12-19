### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return nums

        if len(nums) == 1:
            return [nums]

        return self.fn(nums[0], self.permute(nums[1:]))

    def fn(self, n, pernums):
        size = len(pernums[0]) + 1
        result = []
        for p in pernums:
            pl = []
            for i in range(size):
                p1 = p[:]
                p1.insert(i, n)
                pl.append(p1)
            result.extend(pl)
        return result

```