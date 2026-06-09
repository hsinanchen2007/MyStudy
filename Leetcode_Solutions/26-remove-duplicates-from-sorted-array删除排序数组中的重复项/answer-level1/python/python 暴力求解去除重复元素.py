### 解题思路
注意下标的范围，别超出
1.从原列表的第二个元素“右移”，进行和前一个比较，一样则remove，否则“右移”
2.需注意：当不进行remove时“右移”需要下标+1
         当进行remove时，后序元素会自动左移，此时不需要我们进行“右移”操作

### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        i=1
        while i < n:
            j=i-1
            if nums[i]==nums[j]:
                nums.remove(nums[i]) 
                n=n-1
            else:
                i=i+1
        return len(nums)
```