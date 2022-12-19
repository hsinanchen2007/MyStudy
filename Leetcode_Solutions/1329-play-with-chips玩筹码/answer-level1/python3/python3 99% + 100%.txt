我们可以选择：
1. 将所有奇数位置移至任意偶数位置，并将其余位置移至相同位置
2. 将所有偶数位置移动到任意奇数位置，并将其余位置移动到相同位置
因为奇数位置到奇数位置代价为零，偶数位置到偶数位置代价为零，
所以 minCost = 
min(将奇数位置元素全部移动到任意一个偶数位置的 cost,
将奇数位置元素全部移动到任意一个偶数位置的 cost)
```python
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        even = 0
        for c in chips:
            if c&1==0:
                even+=1
        return min(even,len(chips)-even)
```