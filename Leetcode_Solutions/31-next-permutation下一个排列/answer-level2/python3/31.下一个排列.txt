### 解题思路
参考了powcai的题解。
最后人家要求的是原地修改。
妈耶，不说了，都是泪。洗洗睡吧。
执行用时：32ms      击败73.04%
内存消耗：11.8MB    击败19.50%

### 代码

```python
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        def daoxu(nums,i,j):
                while i<j:
                    nums[i],nums[j]=nums[j],nums[i]
                    i+=1
                    j-=1
                    
        k = 'no'
        for i in range(len(nums)-1):
            if nums[i] < nums[i+1]:
                k = i

        # 最大排列返回逆序
        if k=='no':
            daoxu(nums,0,len(nums)-1)
        else:
            for i in range(len(nums)):
                if nums[i] > nums[k]:
                    m = i

            temp = nums[k]
            nums[k] = nums[m]
            nums[m] = temp

            res = nums[k+1:]
            res = res[::-1]
            
            daoxu(nums,k+1,len(nums)-1)
```