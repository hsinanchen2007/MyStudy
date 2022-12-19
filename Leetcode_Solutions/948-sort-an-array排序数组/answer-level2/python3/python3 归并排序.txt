### 解题思路
此处撰写解题思路
分治思想过于深入，，对其他排序印象不够深入，，冒泡，插入，选择这些过于经典不再写了。快速排序，可以写一写，但是忘了怎么写了，不合格。

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        def helper(nums):
            if len(nums)<=1:
                return nums
            mid = len(nums)//2
            a = helper(nums[:mid])
            b = helper(nums[mid:])
            return merge(a,b)


        def merge(a,b):
            c = []
            i,j=0,0
            while i<len(a) and j<len(b):
                if a[i]<b[j]:
                    c.append(a[i])
                    i+=1
                else:
                    c.append(b[j])
                    j+=1
            c.extend(a[i:] or b[j:])
            return c
        
        return helper(nums)
```