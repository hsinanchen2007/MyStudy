### 解题思路
定义i指向数组第二个元素，从此处开始while循环，比较a[i]和前一个元素a[i-1]的值，如果相同，则删除元素a[i]，如果a[i]不等于a[i-1]，i则指向下一个元素。
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i=1 
        while i<len(nums): 
            if nums[i]==nums[i-1]:  
                nums.pop(i) 
            else:
                i+=1 
        return len(nums)
```
