### 解题思路
1.先找出最大的索引 k 满足 nums[k] < nums[k+1]，如果不存在，就翻转整个数组；
2.再找出另一个最大索引 l 满足 nums[l] > nums[k]；
3.交换 nums[l] 和 nums[k]；
4.最后翻转 nums[k+1:]。
出自[@powcai](/u/powcai/)

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        first_index = -1
        n = len(nums)
        def reverse(nums,i,j):
            while i<j:
                nums[i],nums[j]=nums[j],nums[i]
                i+=1
                j-=1
        for i in range(n-2,-1,-1):
            if nums[i]<nums[i+1]:
                first_index = i
                break
        if first_index == -1:
            reverse(nums,0,n-1)
            return
        second_index = -1
        for i in range(n-1, first_index, -1):
            if nums[i]>nums[first_index]:
                second_index=i
                break
        nums[first_index],nums[second_index]=nums[second_index],nums[first_index]
        reverse(nums, first_index+1,n-1)
```