### 解题思路
使用桶排序。
这里也可以使用快排之类的方法， 但是需要返回输出下标，这个还要做额外处理，最好研究一下。

### 代码

```python3
class Solution:
    def findRelativeRanks(self, nums: List[int]) -> List[str]:
        # 桶排序
        max_val, min_val = nums[0], nums[0]
        for i in range(1, len(nums)):
            max_val = max(max_val, nums[i])
            min_val = min(min_val, nums[i])
        bucket = [-1]*(max_val-min_val+1)
        for i, x in enumerate(nums):
            bucket[x-min_val] = i  # 记录下标
        
        result = [0]*len(nums)
        i = 1
        M = ["", "Gold Medal", "Silver Medal", "Bronze Medal"]
        for x in bucket[::-1]:
            if x != -1:
                if i <=3:
                    y = M[i]
                else:
                    y = str(i)
                result[x] = y
                i += 1
        return result

```