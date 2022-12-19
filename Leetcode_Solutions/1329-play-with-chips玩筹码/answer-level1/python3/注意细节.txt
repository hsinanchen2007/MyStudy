### 解题思路
细节就是：“每个筹码的位置存在数组chips中”，即数组元素表示筹码所在的位置

### 代码

```python3
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        even = odd = 0
        for num in chips:
            if num % 2 == 0:
                even += 1
            else:
                odd += 1
        
        return min(even, odd)
```