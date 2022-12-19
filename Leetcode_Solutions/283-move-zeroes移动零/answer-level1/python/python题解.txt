### 解题思路
在数组末尾设置结束的标志，需要循环访问数组，如果当前数值等于0则pop()掉，并在最后append()上一个0，当遇到结束标志时则退出循环，此时i的索引就是结束
标志的索引，将索引pop()出来。

### 代码

```python
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        nums.append('end')
        l = nums.count(0)
        i = 0
        while nums[i] != 'end':
            if nums[i] == 0:
                nums.pop(i)
                nums.append(0)
                i = 0
            else:
                i += 1
                

        nums = nums.pop(i)
        return nums
```