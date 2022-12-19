### 解题思路
借鉴别人的解释：
因为移动2个位置不需要代价，那么奇数位置移到奇数位置不用代价，偶数位置移到偶数位置不用代价，
那就分别统计奇数位置和偶数位置的个数，相当于把所有奇数放一起，所有偶数的放一起，
然后比较奇数的少还是偶数的少，将少的个数移到多的个数位置上去就可以了

### 代码

```python3
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        odd = sum(1 for i in chips if i%2 == 1)
        return min(odd, len(chips)-odd)
```