### 解题思路
此处撰写解题思路
非常简单的dfs题目，先找到坐标的数位和是否小于等于k，小于等于就算一个，继续递归。
然后就是因为上下左右移动，所以走过了的一个hash记录不再重复走，这里的四周扩散的坐标获取函数也是固定的，基本固定的dfs模板写出来的。
sys.setrecursionlimit(10000) 用来学习的，加不加无所谓的。。之前的题目那么难，，今天的有点简单
### 代码

```python3
sys.setrecursionlimit(10000)
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        
        def helper(i,j):
            ans = 0
            while i:
                ans+=i%10
                i=i//10
            while j:
                ans+=j%10
                j=j//10
            return ans<=k
        
        def neighbour(i,j):
            for r,c in ((i-1,j),(i+1,j),(i,j-1),(i,j+1)):
                if 0<=r<m and 0<=c<n:
                    yield r,c
                
        self.ans=0
        visited=set()
        def dfs(i,j,visited):
            if (i,j) in visited:
                return
            if helper(i,j):
                visited.add((i,j))
                self.ans+=1
                for r,c in neighbour(i,j):
                    if helper(r,c):
                        dfs(r,c,visited)

        dfs(0,0,visited)
        return self.ans


            
```