### 解题思路
1.找到車的位置
2.四個方向遇到象break,遇到兵就+1,break
### 代码

```python3
class Solution:
    def numRookCaptures(self, g: List[List[str]]) -> int:        
        y,x=0,0
        l=[0, 1, 2, 3, 4, 5, 6, 7]
        ans = 0
        for r in range(8):
            for c in range(8):
                if g[r][c] == 'R':
                    y,x = r,c
        for i in l[x:8]:
            if g[y][i] == "B":
                break
            if g[y][i] == "p":
                ans += 1
                break
        if x:
            for i in range(x-1,-1,-1):
                if g[y][i] == "B":
                    break
                if g[y][i] == "p":
                    ans += 1
                    break
        for j in l[y:8]:
            if g[j][x] == "B":
                 break
            if g[j][x]== "p":
                ans += 1
                break
        if y:
            for j in range(y-1,-1,-1):
                if g[j][x] == "B":
                    break
                if g[j][x] == "p":
                    ans += 1
                    break
        
        return ans

```