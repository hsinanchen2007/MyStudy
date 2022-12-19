### 解题思路
由于移动两个单位时代价为0，因此所有的偶数位置上面的筹码均可以移动到位置2上，代价为0.奇数位置上的筹码可以移动到位置1上，代价也为0.此时将位置1和位置2中筹码移动到另一个位置上即可，即返回数组中偶数个数和奇数个数中的较小者。

### 代码

```python3
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        odd=0
        even=0
        for chip in chips:
            if chip%2==0:
                even+=1
            else:
                odd+=1
        return min(odd,even)
```

![image.png](https://pic.leetcode-cn.com/b61e30acdc86a4133ca9fa2d2727cd4d0b889cd1f1fe119d3aebec53c8d0eb47-image.png)
