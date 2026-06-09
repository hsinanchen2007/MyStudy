### 解题思路
回溯问题只需要将问题转换成树状图，然后进行深度优先遍历即可：

![image.png](https://pic.leetcode-cn.com/cfd606fb8914e8dc5c21ec111ef8ff1888dd792686307952390c89e61d8d8e0b-image.png)



### 代码

```python3
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:

        res = []
        def backtrack(tiles, path):
            if tiles == []:
                return 
            for i in range(len(tiles)):
                cur = tiles[i]
                if (path + cur) not in res:
                    res.append(path + cur)
                    backtrack(tiles[:i] + tiles[i+1:], path + cur)
                
        backtrack(tiles, '')
        return len(res)
```