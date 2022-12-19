将数组转为set集合去除可能存在的重复元素，再判断集合的长度，若长度小于3，则返回集合的最大值，若集合长度大于等于3，即原数组存在第三大的元素，则连续两次删除集合最大元素，得到的集合的最大值即为原数组的第三大元素。时间复杂度为O(n)
```
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        set_nums = set(nums)
        if len(set_nums) < 3:
            return max(set_nums)
        else:
            set_nums.remove(max(set_nums))
            set_nums.remove(max(set_nums))
            return max(set_nums)


```
