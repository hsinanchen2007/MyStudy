```
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-1,0,-1):
            if nums[i]>nums[i-1]:
                for j in range(len(nums)-1,i-1,-1):
                    if nums[j]>nums[i-1]:   #在后面找比自己大的最小的去换
                        nums[j],nums[i-1]=nums[i-1],nums[j]#交换之后nums[i:]是有序的，降序
                        for k in range(i,i+(len(nums)-i)//2):
                            nums[k],nums[len(nums)+i-1-k]=nums[len(nums)-k+i-1],nums[k]#nums[i:]反转
                        return
        for i in range(len(nums)//2):
            nums[i],nums[len(nums)-1-i]=nums[len(nums)-1-i],nums[i] #交换反转，nums是降序的

```
据说不能用切片[::-1]来反转，因为切片之后其实还是一个数组，而数组属于可变类型。