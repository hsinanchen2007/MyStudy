### 解题思路
简单的回溯法，走一遍例子就会懂

### 代码

```python3
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        def helper(nums,target,index):
            '=0，可以划分'
            if target==0:
                return True
            '这条路径不可划分'
            if index>=len(nums) or target<0:
                return False
            '选择当前数字nums[index]'
            if(helper(nums,target-nums[index],index+1)):
                return True
            '选择当前nums[index]没有划分划分成功'
            '跳过当前nums[index]'
            j=index+1;
            '减枝操作，防止超时'
            '选择当前num[index]没有划分成功，则选择下一个和nums[index]一样的数也划分不成功'
            while j<len(nums) and nums[index]==nums[j]:
                j=j+1
            '不选择当前nums[index]'
            return helper(nums,target,j)

        s= sum(nums)
        if s%2!=0:
            return False
        target=s/2
        return helper(nums,target,0)
      

    
```