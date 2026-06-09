### 解题思路
nums为空或长度为1是特例，分别解决即可。对数组nums排序后，若目标元素val在nums中，则val一定处于某个索引范围内。因此采用双指针，一个指针标示val的开始，另一指针标识val的结束;再利用for循环进行逆序删除即可。

### 代码

```python
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        n = len(nums)
        nums.sort()
        left = 0
        if n == 0:
            return 0
        if n == 1:
            if nums[0] == val:
                del nums[0]
                return 0
            else:
                return n
                
        while left < n and nums[left] != val:
            left += 1

        if left == n:
            return n
        else:
            right = left
            while right < n - 1 and nums[right + 1] == nums[left]:
                right += 1
        for i in range(right, left - 1, -1):
            del nums[i]
        new_length = n - right + left + 1
        return new_length
```