### 解题思路
双指针，只用了1/2长度的target数组，因为slow超过target一半肯定就没有解了

### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        if target <= 2:
            return []
        arr = range(1, target/2 + 2)
        sumnum, slow = 3 , 0
        fast = 1
        res = []
        while slow <= target/2 and fast < len(arr):
            if sumnum == target:
                res.append(arr[slow:fast+1])
                fast += 1
            elif sumnum < target:
                fast += 1
            elif sumnum > target:
                slow += 1
            sumnum = sum(arr[slow: fast+1])
        return res



```