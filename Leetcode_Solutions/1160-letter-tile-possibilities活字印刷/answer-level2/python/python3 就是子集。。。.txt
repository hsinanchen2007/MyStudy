### 解题思路
此处撰写解题思路
和自己的题目一样的，但是排序去重为啥时间这么长，有点疑问，。
### 代码

```python3
import itertools
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        ans=0
        for i in range(1,len(tiles)+1):
            ans += len(set(itertools.permutations(tiles,i)))
        return ans
        # self.ans = 0

        # tiles = "".join(sorted(tiles))
        # def helper(tiles,k):
        #     if k==0:
        #         self.ans+=1
        #     pre = ''
        #     for i in range(len(tiles)):
        #         if tiles[i]!=pre:
        #             helper(tiles[:i]+tiles[i+1:],k-1)
        #         pre = tiles[i]
        
        # for i in range(1,len(tiles)+1):
        #     helper(tiles,i)
        # return self.ans

```