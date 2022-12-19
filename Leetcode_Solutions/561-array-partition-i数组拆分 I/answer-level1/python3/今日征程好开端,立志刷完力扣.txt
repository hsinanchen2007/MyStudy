### 解题思路
为题本源找到,找其每个组合的最小值之和,实则就是对其就行分组取奇数为数相加得到结果

### 代码

```python3
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        res = 0
        nums.sort()
        for i in range(0,len(nums),2):
            res +=  nums[i]
        return res


```