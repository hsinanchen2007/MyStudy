### 解题思路
看到题目很自然地想到遍历整个数组，比较`i`和`i+1`是否相同，如果相同则删除其中一位。
但是从`[0,n-1]`遍历的话，因为删除后数组长度也会跟着变化，不好确定。
所以想到了从后往前遍历，删除当前元素，对前面的元素的下标没有任何影响。
虽然可以解出来，但耗时很不理想，可能官方的双指针的方法会好一点吧。

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        for i in range(len(nums)-1, 0, -1):
            if nums[i]==nums[i-1]:
                nums.pop(i)                  
        return len(nums)
```