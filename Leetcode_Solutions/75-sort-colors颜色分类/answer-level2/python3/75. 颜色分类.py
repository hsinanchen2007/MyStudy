使用三指针方法，第一个指针i负责遍历，第二个指针j负责维护[0,j)的全0序列，第三个指针负责维护[k,n)的全2序列


```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j, k, i = 0, len(nums), 0
        while i < k:
            if nums[i] == 0:
                nums[i],nums[j] = nums[j], nums[i]
                j += 1
                i += 1
            elif nums[i] == 1:
                i += 1
            else:
                nums[i], nums[k-1] = nums[k-1], nums[i]
                k -= 1
```
