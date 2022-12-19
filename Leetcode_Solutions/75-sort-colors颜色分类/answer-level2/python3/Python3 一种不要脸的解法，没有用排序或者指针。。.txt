没有用排序，没有用指针，直接改变原数组。。。唔，我承认这种方法很没水平

```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        a = nums.count(0)
        b = nums.count(1)
        c = nums.count(2)
        for i in range(a):
            nums[i] = 0
        for i in range(a,a+b):
            nums[i] = 1
        for i in range(a+b,len(nums)):
            nums[i] = 2

```

