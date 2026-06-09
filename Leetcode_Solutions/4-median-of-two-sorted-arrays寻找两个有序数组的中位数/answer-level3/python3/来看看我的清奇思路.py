废话不多说，直接上代码！

```python []
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        pos_nums, neg_nums, newList = [], [], []
        nums = nums1 + nums2
        total_length = len(nums)
        for value in nums:
            if value < 0:
                length = len(neg_nums)
                value1 = abs(value)
                if value1 > length - 1:
                    neg_nums.extend([0]*(value1-length+1))
                neg_nums[value1] += 1
            else:
                length = len(pos_nums)
                if value > length - 1:
                    pos_nums.extend([0]*(value-length+1))
                pos_nums[value] += 1

        neg_length = len(neg_nums)
        for index in range(neg_length-1, -1, -1):
            if neg_nums[index] is not 0:
                newList.extend([-index]*neg_nums[index])

        for index, v in enumerate(pos_nums):
            if v is not 0:
                newList.extend([index]*v)

        half = total_length // 2
        return float(newList[half]) if total_length & 1 else float(newList[half-1] + newList[half])/2
```

