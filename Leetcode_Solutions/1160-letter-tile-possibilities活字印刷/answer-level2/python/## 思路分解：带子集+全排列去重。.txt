```python3
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        self.count = 0 
        ## 为去重做准备
        tiles = sorted(tiles)
        self.helper(tiles, [])
        return self.count

    def helper(self, tiles, path):
        ## 加入子集
        if path:
            self.count += 1 
        ## 去重排列
        for i in range(len(tiles)):
            if i != 0 and tiles[i-1] == tiles[i]:
                continue
            self.helper(tiles[:i] + tiles[i+1:], path+[tiles[i]])