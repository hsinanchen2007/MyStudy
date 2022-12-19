以步长为2遍历nums的下表，而后利用list与整数的乘法得到每一个step的目标数组

```
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        result = []
        for i in range(1, len(nums), 2):
            temp = [nums[i]] * nums[i-1]
            result.extend(temp)
        return result
```


