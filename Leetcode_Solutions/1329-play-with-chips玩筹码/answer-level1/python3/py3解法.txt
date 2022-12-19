### 解题思路
主要是看明白题目，就是找出数组中奇数和偶数数量较少的那个的数量，代码简单。

### 代码

```python3
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        odd_num = 0
        even_num = 0
        
        for i in range(len(chips)):
            if chips[i]%2 == 0:
                even_num += 1
            elif chips[i]%2 == 1:
                odd_num += 1
                
        return min(odd_num, even_num)
```