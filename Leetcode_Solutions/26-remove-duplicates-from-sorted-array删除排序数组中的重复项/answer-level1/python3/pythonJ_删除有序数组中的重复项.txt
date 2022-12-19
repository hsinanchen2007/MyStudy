### 解题思路
方法一：指针法
构造指针保留最后一个不重复的元素，遍历过程对比元素，如果不同，则覆写

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        flag=0
        if len(nums)==0:
            return flag
        for i in range(1,len(nums)):
            if nums[i]!=nums[flag]:
                flag+=1
                nums[flag]=nums[i]
        return flag+1
```

### 解题思路
方法二：删除重复元素

### 代码
```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i=1
        while i<=len(nums)-1:
            if nums[i]==nums[i-1]:
                del nums[i]
            else:
                i+=1
        return len(nums)
```