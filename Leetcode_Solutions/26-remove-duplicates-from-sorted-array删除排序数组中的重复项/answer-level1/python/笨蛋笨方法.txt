### 解题思路
为了避免超出范围，使用数与其-1位置的数进行比较，相同则删除，不同则下一个，当相同时因为已经删除了一个数，所以标明序列位置的i次是不需要增加。
设一个计数器，每当有两个数不相等时即+1；而当nums存在时，计数器默认为1.
### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if nums:
            a = len(nums)
            count = 1
            i = 1
            while i <= a-1:
                if nums[i] == nums[i-1]:
                    del nums[i]
                    
                    a -= 1
                else:
                    i += 1
                    count += 1
        else:
            count = 0
        return count
```