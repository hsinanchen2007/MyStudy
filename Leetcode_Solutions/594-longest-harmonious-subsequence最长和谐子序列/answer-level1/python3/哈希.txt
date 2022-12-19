### 解题思路


### 代码

```python3
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        ans = 0
        dic = dict(collections.Counter(nums))
        for k,v in dic.items():
            if k+1 in dic:
                ans = max(ans, v+dic[k+1])
        return ans



```