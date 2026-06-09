
### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # 锻炼一下自己的快速排序
        if not nums or len(nums)==1:
            return nums
        left_nums,right_nums=[],[]
        mid_num=nums[len(nums)//2]
        nums.remove(mid_num)
        for num in nums:
            if num>mid_num:
                right_nums.append(num)
            else:
                left_nums.append(num)
        return self.sortArray(left_nums)+[mid_num]+self.sortArray(right_nums)

            
        
```