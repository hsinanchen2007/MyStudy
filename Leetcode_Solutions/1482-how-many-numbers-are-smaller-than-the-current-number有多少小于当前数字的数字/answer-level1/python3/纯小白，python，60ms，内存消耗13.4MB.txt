### 解题思路
一开始想2次循环，后来想了想，可以在知道要找哪个数的情况下排序一次就行了

### 代码

```python3
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:  
        t = []
        list1 = sorted(nums)
        for i in range(len(nums)):
            t.append(list1.index(nums[i]))
        return t

```