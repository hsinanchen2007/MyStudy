### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        j=0
        o=0
        for i in chips:
            if(i%2):
                j+=1
            else:o+=1
        return min(j,o)
```