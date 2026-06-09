### 解题思路
开辟新的列表存储合格列表，对原列表进行扫描，如果当前元素大于所有元素就加入到结果列表中，如果小于等于某个元素就用它替换。

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        res = [nums[0]]
        for i in range(1, len(nums)):
            var = nums[i]
            for j in range(len(res)):
                if var <= res[j]:
                    res[j] = var
                    break
            else:
                res.append(var)
        return len(res)
```