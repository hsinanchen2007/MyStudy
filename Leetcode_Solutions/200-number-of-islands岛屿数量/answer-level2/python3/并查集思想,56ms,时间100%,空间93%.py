首先逐行记录每一行产生的连通域,并记录与前一行连通域是否相连.

然后我们就得到一些点(每一行上连通的部分)和这些点之间的边.

用并查集思想对这些点进行并操作.求出集合个数

这么做并查集的粒度更大,省去了为原图中每个点查找,并操作的开销.


```python
def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        if m  == 0:
            return 0
        n = len(grid[0])
        
        p = set()
        flag =[[0 for i in range(n)] for j in range(m)]
        count = 0
        for i in range(m):
            if grid[i][0] == "1":
                count += 1
                flag[i][0] = count
                if i >0 and flag[i-1][0] > 0:
                    p.add((flag[i-1][0],count))
            for j in range(1,n):
                if grid[i][j] == "0": continue
                
                if flag[i][j-1]:
                    flag[i][j] = flag[i][j-1]
                else:
                    count += 1
                    flag[i][j] = count
                if i > 0 and flag[i-1][j]:
                    p.add((flag[i-1][j],count))
        
        def union(a,b,par):
            while par[a] > 0:
                a = par[a]
            while par[b] > 0:
                b = par[b]
            
            if a != b:
                par[a] = b
            
        ans = [-1 for i in range(count+1)]
        for i in p:
            union(i[0],i[1],ans)
        
        res= 0
        for i in range(1,count+1):
            if ans[i] < 0:
                res += 1
        return res
                
```