### 解题思路
因为所有节点都可以无代价转化为0或1，所以统计奇数和偶数的个数，然后返回最小的个数就可以了

### 代码

```python3
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        temp1, temp2 = 0, 0 
        for i in chips:
            if i % 2 == 0:
                temp1 += 1
            else:
                temp2 += 1
        return min([temp1, temp2])
```