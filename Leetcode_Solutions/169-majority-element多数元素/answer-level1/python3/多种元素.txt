题目说一定存在大多数元素，所以排序然后返回中间的元素即可！
```
def majorityElement(self, nums: List[int]) -> int:
        nums.sort() #排序返回中间的即可
        return nums[len(nums)//2]
```
