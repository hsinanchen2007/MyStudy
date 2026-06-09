这题首先要明白题目的意思: 返回值是数组长度len，输出值是数组，所以要保证数组的前len个为非重复元素即可。
利用双指针i,j。i指向非重复值，j用于数组遍历，
    当nums[j]==nums[i],j++  # 跳过重复值
    当nums[j]!=nums[i], nums[i+1]=nums[j]，i+=1  # 找到非重复值，复制到第一个重复值的位置，更新i
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        for j in range(1, len(nums)):
            if nums[j] != nums[i]:
                nums[i + 1] = nums[j]
                i+=1
        return i+1
```
