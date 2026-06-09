第一种解法递归DFS
```
class Solution:
    def stoneGame(self,piles) -> bool:
        s = sum(piles)
        self.awin = False
        def helper(piles,l,r,all):
            if l + 1 == r:
                all += max(piles[l],piles[r])
                if all > s // 2:
                    self.awin = True
                    return
            helper(piles,l+1,r,all + piles[l])
            if self.awin:
                return
            helper(piles,l,r-1,all + piles[r])
            if self.awin:
                return
        helper(piles,0,len(piles) - 1,0)
        return self.awin
```
可以对上面的代码进行修改，采用带返回值的递归函数，可以减少代码量
```
class Solution:
    def stoneGame(self,piles) -> bool:
        s = sum(piles)
        def helper(piles, l, r, all):
            if l + 1 == r:
                all += max(piles[l], piles[r])
                if all > s // 2:
                    return True
                return False
            if helper(piles, l + 1, r, all + piles[l]) or helper(piles, l, r - 1, all + piles[r]):
                return True
        return helper(piles, 0, len(piles) - 1, 0)
```
由上面的递归解法可以分析出一种类似于动态规划的前缀和解法
```
class Solution:
    def stoneGame(self,piles) -> bool:
        s = sum(piles)
        res = [[0 for _ in range(len(piles)+1)] for _ in range(len(piles)+1)]
        for i in range(len(res)-2,-1,-1):
            res[0][i] = res[0][i+1] + piles[i]
            if i % 2 == 1 and res[0][i] > s // 2:
                return True
        for j in range(1,len(res)):
            res[j][len(res)-1] = res[j - 1][len(res) - 1] + piles[j-1]
            if (len(res) - 1 + j) % 2 == 1 and res[j][len(res)-1] > s // 2:
                return True
        for i in range(1,len(res)):
            for j in range(0,len(res)-2):
                res[i][j] = res[i-1][j] + piles[i-1]
                if (i + j) % 2 == 1 and res[i][j] > s // 2:
                    return True
        return False
```
最后经过这么多分析，可以发现一种规律性的解法
```
class Solution:
    def stoneGame(self,piles) -> bool:
        return True
```



