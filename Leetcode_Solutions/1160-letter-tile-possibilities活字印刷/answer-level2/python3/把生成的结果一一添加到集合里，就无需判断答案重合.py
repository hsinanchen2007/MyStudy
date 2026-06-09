Python
用集合，简单粗暴
1：库函数
```
from itertools import permutations
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        ans = set()
        for i in range(1,len(tiles)+1):
            for j in permutations(tiles,i):
                ans.add(j)
        return len(ans)
```
2:回溯
```
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        ans = set()
        def helper(left,right):
            if left:
                ans.add(left)
            for i in range(len(right)):
                helper(left+right[i],right[:i]+right[i+1:])
        helper('',tiles)
        return len(ans)
