### 解题思路
此处撰写解题思路
解题思路
        。数组已经排好序了，所以只需要以此找到不重复的元素替换到重复的元素就可以
        。使用两个指针i，j，最开始i指针指向0下标，j指针指向1下标，后面的逻辑依次：
           1. 如果j的值与i的值不同时，i+1，j+1，开始新的循环
           2. 如果j的值与i的值相同，j+1然后查找与i不同的值，找到后替换j与i+1的值，然后i+1，j+1
           3. 重复上面步骤，直到j=length，没有其他新的元素
           4. 将i后面的元素删除,使用python截取操作
           5. 
### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        
        """
        i,j = 0, 1
        if len(nums) == 0:
            return
        length = len(nums)
        while j < length:
            if nums[i] != nums[j] and j == i + 1:
                i += 1
                j += 1
                continue
            if nums[i] != nums[j] and j > i + 1:
                i += 1
                nums[i] = nums[j]
                j += 1
                continue
            if nums[i] == nums[j]:
                j += 1
        
        nums = nums[:i+1]
        return len(nums)
                        
           

                                

        
```