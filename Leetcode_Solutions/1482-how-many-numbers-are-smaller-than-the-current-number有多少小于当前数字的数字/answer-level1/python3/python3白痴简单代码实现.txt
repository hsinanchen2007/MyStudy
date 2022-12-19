```
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        new = sorted(nums)
        L = []
        for num in nums:
            L.append(new.index(num))
        return L
```
思路很简单，先排序，排序之后，其所在index值就是比它小的数值的个数。很简单吧～
欢迎关注萌新公众号呀 闪闪AI  