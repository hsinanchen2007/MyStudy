### 解题思路
快速排序 将数组第一个元素作为基准值fenge_num，遍历数组，将小于等于基准值的元素加入到left数组中（不包括第一个元素），将大于基准值的元素加入到right数组中。再对left/right两数组进行上述步骤sortArray()。
返回每次的基准值self.sortArray(left)+[fenge_num]+self.sortArray(right) ，达成排序  

### 代码

```python
class Solution(object):
    def sortArray(self, nums):
        if not nums:         
            return []
        fenge_num=nums[0]
        left=[]
        right=[]
        n=len(nums)
        for i in range(1,n):    # 注意跳过第一个元素
            if nums[i]<=fenge_num:
                left.append(nums[i])
            elif nums[i]>fenge_num:
                right.append(nums[i])
        return self.sortArray(left)+[fenge_num]+self.sortArray(right)
 
    
```