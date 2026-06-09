### 解题思路
继续使用[排除法](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)来做二分查找。
只是这里需要使用 n = n + (x+mid-1)//mid 来统计不超一小时记作一小时。

### 代码

```python3
class Solution:
    def eat_out(self, mid, piles, H):
        n = 0
        for x in piles:
            #n = n + (x//mid) + 1 # bug x == mid, 会多1
            n = n +(x+mid-1)//mid  # or  n = n +(x-1)//mid +1
        if n <= H:
            return True
        else:
            return False


    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        left = 1
        right = max(piles)
        while left<right:
            mid = int((left+right)/2)
            if self.eat_out(mid, piles, H):
                right = mid
            else:
                left = mid+1

        return left
```