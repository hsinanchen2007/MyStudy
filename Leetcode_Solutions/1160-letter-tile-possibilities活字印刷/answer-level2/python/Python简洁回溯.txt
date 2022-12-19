```
class Solution(object):
    def numTilePossibilities(self, tiles):
        # 统计出现的大写字母的数量
        dic = {x:tiles.count(x) for x in set(tiles)}
        self.ans = 0
        # 回溯
        def dfs(depth=0):
            if depth > 0: self.ans += 1
            # 同一层不会出现两个相同的大写字母，故放心枚举
            for key in dic:
                # 只要没用完就可以一视同仁
                if dic[key] > 0:
                    dic[key] -= 1
                    dfs(depth+1)
                    dic[key] += 1
        dfs()
        return self.ans
```
