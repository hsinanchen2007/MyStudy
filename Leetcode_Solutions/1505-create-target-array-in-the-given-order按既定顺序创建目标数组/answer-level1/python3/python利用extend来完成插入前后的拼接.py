主要是插入操作，先进行分割左，右list，然后左list添加元素，然后extend拼接。
```
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        res = []
        for i in range(len(nums)):
            if len(res) == 0:
                left = []
                right = []
            else:
                right = res[index[i]:]
                left = res[:index[i]]
            left.append(nums[i])
            left.extend(right)
            res = left
        return res
```
