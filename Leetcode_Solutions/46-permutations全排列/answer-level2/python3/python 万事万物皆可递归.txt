### 解题思路
递归: 
【1, 2, 3】 => [1, 2] + 3
[1, 2] => [1] + 2
[1] return [1]

2 + [1] => [1, 2], [2, 1] # 2 可插入的位置为1前和1后 
3 + [[1, 2], [2, 1]] => [[3, 1, 2], [1, 3, 2], [1, 2, 3], [3, 2, 1] ...] # 3 对于每个数组每个位置进行插入


### 代码

```python3
from typing import List
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1: return [nums]
        res = self.permute(nums[:-1])
        l, col = len(res), len(res[0])
        tempRes = []
        
        for i in range(l):
            for j in range(col + 1):
                temp = res[i].copy()
                temp.insert(j, nums[-1])
                tempRes.append(temp)
        return tempRes

```