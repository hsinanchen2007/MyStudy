运用python3的count，sort方法，题目所求的数必然会位于sort后的数组的中间位置，然后我们就求这个数出现的次数，如果大于一半，就返回这个数；否则就返回-1
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if nums is None:
            return -1
        nums.sort()
        mid=int(len(nums)/2)
        if nums.count(nums[mid])>int(len(nums)/2):
            return nums[mid]
        else:
            return -1
```
![Screen Shot 2020-03-04 at 4.08.31 PM.png](https://pic.leetcode-cn.com/794528438022639ee72d5a10620ea38149549e402f597f8af892a8a5c7e069a8-Screen%20Shot%202020-03-04%20at%204.08.31%20PM.png)
