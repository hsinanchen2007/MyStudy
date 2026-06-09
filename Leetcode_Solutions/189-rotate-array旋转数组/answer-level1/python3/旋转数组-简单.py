### 解题思路
思路1: 循环k次，暴力破解，但是会超时
思路2: reverse3次
思路3: list切片，取后n个nums[-n:]和前l-n个nums[:-n]

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = k % len(nums)
        nums[0:] = nums[-n:] + nums[:-n]
```