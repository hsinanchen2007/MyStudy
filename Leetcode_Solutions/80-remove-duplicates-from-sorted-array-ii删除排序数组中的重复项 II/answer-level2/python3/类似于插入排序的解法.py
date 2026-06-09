### 解题思路
此处撰写解题思路
算法基础不好，也不知道这种解法叫什么名字。但是思想类似于插入排序。
如果找到这个重复的值，就把他移到最后。
### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l = len(nums)
        i = 2
        while i<= l-1:
            if nums[i] == nums[i-2]:
                tmp = nums[i]
                for j in range(i,l-1):
                    nums[j] = nums[j+1]
                nums[l-1] = tmp
                l -= 1
            else:
                i+= 1
            
        return i
        

```