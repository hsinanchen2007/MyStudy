### 解题思路
1."所有组合" => 递归
2.先选出一个数+后面两位的全排列

### 代码

```python3
class Solution:

    def permute(self, nums: List[int]) -> List[List[int]]:
        # “所有组合” => 递归
        lens = len(nums)
        if lens <= 1:
            return [nums]
        else:
            k = []
            for i in range(lens):
                k += [[nums[i]]+j for j in self.permute(nums[:i]+nums[i+1:])]
            return k


        

```