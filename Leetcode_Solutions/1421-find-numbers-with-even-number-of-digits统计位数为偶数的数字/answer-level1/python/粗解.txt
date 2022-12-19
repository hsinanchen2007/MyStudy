### 解题思路
这道题我先用整除号来判断单个数字元素的位数，再与2取模判断位数是不是偶数，最后每次循环时，把计数器count置为0，然后进行下一轮循环的判断

### 代码

```python
class Solution(object):
    def findNumbers(self, nums):
        dight = 0
        for i in range(0,len(nums)):
           count = 0
           while nums[i] != 0:
              nums[i] //= 10
              count +=1  
           if count % 2 == 0:
              dight +=1
        return dight

```