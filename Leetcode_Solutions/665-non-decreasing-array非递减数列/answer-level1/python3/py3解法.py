思路：
从头开始遍历，当遇到第一次递减时，处理数组，有三种情况
1.第一个元素就大于第二个元素，把第一个元素的值改成第二个元素的值
2.递减数对的第二个数，比数对前一个元素小时，把数对第二个值改成第一个的值
3.递减数对的第二个数，比数对前一个元素大时，把数对第一个值改成第二个的值
这个递减数对被处理后，重新遍历数组，发现第二个递减数对直接返回False。
```
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        for i in range(len(nums)-1):
            if nums[i] > nums[i+1]:
                if i==0:
                    nums[0]=nums[1]
                elif nums[i-1]>nums[i+1]:
                    nums[i+1]=nums[i]
                elif nums[i-1]<nums[i+1]:
                    nums[i]=nums[i-1]
                break
        for i in range(len(nums)-1):
            if nums[i] > nums[i+1]:
                return False
        return True
```
