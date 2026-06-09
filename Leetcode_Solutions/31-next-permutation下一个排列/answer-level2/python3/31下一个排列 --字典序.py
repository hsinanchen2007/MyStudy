### 解题思路
字典序：
0.初始化idx=idx=-1
1.从右到左遍历nums，发现第一个小于右边的数nums[i],记录idx1=i
2.将idx1+1之后的数升序排序
3.从左到右遍历nums[idx1+1:],找到第一个大于nums[idx1]的数nums[j],记录idx2=j
4.将索引idx1和idx2所对应的数交换

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        idx1=idx2=-1#0.initialization
        for idx in range(len(nums)-2,-1,-1):#1.1st round
            if nums[idx]<nums[idx+1]:
                idx1=idx
                break
        nums[(idx1+1):] = sorted(nums[(idx1+1):])#2.sorted from idxi+1 
        for idx in range(idx1+1,len(nums)):
            if nums[idx]>nums[idx1]:
                idx2=idx
                break
        nums[idx1],nums[idx2]=nums[idx2],nums[idx1]#3.change the index
```