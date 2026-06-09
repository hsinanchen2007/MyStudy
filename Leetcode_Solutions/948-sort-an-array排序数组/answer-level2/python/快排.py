### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def qsort(a,b):
            i=a-1
            for j in range(a,b):
                if nums[j]<nums[b]:
                    i+=1
                    nums[i],nums[j]=nums[j],nums[i]
            i+=1
            nums[i],nums[b]=nums[b],nums[i]
            return i
        
        def helper(a,b):
            if a>=b:
                return
            k=random.randint(a,b)
            nums[k],nums[b]=nums[b],nums[k]
            p=qsort(a,b)
            helper(a,p)
            helper(p+1,b)
        
        helper(0,len(nums)-1)
        return nums



```