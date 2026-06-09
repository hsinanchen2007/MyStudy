### 解题思路
回溯算法:到第k层返回即可，其余与全排列相似
又注意到[1,2]和[2,1]是同一个组合；
与排列不同，这里对下一次的深入搜索时需要更改start
不在nums上修改而是直接用顺序输入，不用visited数组
**PS：**可以使用itertools.combinations(n,k)
### 代码

```python3
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        #回溯算法:到第k层返回即可，其余与全排列相似
        #又注意到[1,2]和[2,1]是同一个组合，与排列不同，这里对下一次的深入搜索时需要更改start
        if n<=0 or k<=0 or k>n: return []#special case
        nums=[x for x in range(1,n+1)]
        start=1
        path=[]
        res=[]
        depth=0
        def DFS(nums,start,path,res,depth):
            if depth==k:
                res.append(path[:])
                return
            for i in range(start,len(nums)+1):
                    start=i+1
                    path.append(i)
                    DFS(nums,start,path,res,depth+1)
                    path.pop()
                    start=i-1
        DFS(nums,start,path,res,depth)
        return res
```