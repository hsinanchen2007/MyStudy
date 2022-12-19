### 解题思路
排序后好解。

这里主要是要注意有相同值，也无法构成顺子。
没有注意此，第一次提交就报错了.

注意到，不排序也有解法。


### 代码

```python3
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        nums.sort()
        if nums[0]>0:
            for i in range(1,5):
                if nums[i] != nums[i-1]+1:   
                    return False
            return True
        else:
            zero_n = 0
            for i in range(5):
                if nums[i] == 0:
                    zero_n += 1
                else:
                    break
            gap = 0
            for j in range(i+1, 5):
                if nums[j] == nums[j-1]: # 这里还需要考虑等于的情况
                    return False
                else:
                    gap += nums[j] - nums[j-1]-1
            return gap<=zero_n
```