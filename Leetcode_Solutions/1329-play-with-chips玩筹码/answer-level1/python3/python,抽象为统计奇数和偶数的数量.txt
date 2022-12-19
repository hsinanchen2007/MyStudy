### 解题思路
奇数位置移动到奇数位置代价为零，偶数位置移动到偶数位置代价为零
把所有奇数位置移动到同一个奇数位置，把所有偶数位置移动到同一个偶数位置，并且偶数位置和奇数位置之差1（必然可以做到）
然后只需要把奇数位置筹码移动到偶数位置，或者偶数位置的筹码移动到奇数位置
怎么移呢，哪个少移动哪个呗 min(奇数，偶数)

### 代码

```python3
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        odd=even=0
        for pos in chips:
            if pos%2==0:
                even+=1
            elif pos%2==1:
                odd+=1
        return min(odd,even)

```