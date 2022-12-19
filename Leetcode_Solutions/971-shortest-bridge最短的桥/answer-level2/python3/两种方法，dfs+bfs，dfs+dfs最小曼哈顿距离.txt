我这里两个方法速度差不多,宽搜略快一点。

先深搜岛1边缘，然后宽搜扩张，遇到岛2就返回：

```
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        m,n=len(A),len(A[0])
        a=set()
        d=[(-1,0),(1,0),(0,-1),(0,1)]
        
        def f(i,j):
            A[i][j]=2       #扫描标记
            edge=False
            for p,q in d:
                x,y=i+p,j+q
                if 0<=x<m and 0<=y<n:
                    if A[x][y]==0:
                        edge=True
                    elif A[x][y]==1:
                        f(x,y)
            if edge:        #加入边缘集合
                a.add((i,j))
        
        for i in range(m):
            for j in range(n):
                if A[i][j]==1:
                    f(i,j)      #深搜岛1的边缘
                    ans=0
                    while True:     #宽搜边缘扩张
                        tmp=set()
                        for u,v in a:
                            for p,q in d:
                                x,y=u+p,v+q
                                if 0<=x<m and 0<=y<n:
                                    if A[x][y]==1:      #遇到岛2就返回
                                        return ans
                                    elif A[x][y]==0:        #否则就标记新边缘
                                        A[x][y]=2
                                        tmp.add((x,y))
                        ans+=1
                        a=tmp
```

先深搜岛1边缘，再深搜岛2边缘，再统计两个岛边缘各个点的最小曼哈顿距离，也能ac。

```
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        m,n=len(A),len(A[0])
        d=[(-1,0),(1,0),(0,-1),(0,1)]
        ans=m+n
        
        a=set()
        def f(i,j):
            A[i][j]=2
            edge=False
            for p,q in d:
                x,y=i+p,j+q
                if 0<=x<m and 0<=y<n:
                    if A[x][y]==0:
                        edge=True
                    elif A[x][y]==1:
                        f(x,y)
            if edge:
                a.add((i,j))     #加入岛1边缘集合
                
        b=set()
        def g(i,j):
            nonlocal ans
            if ans==2:
                return
            A[i][j]=2
            flag=False
            for p,q in d:
                x,y=i+p,j+q
                if 0<=x<m and 0<=y<n and (x,y) not in b:
                    if A[x][y]==0 and not flag:
                        for u,v in a:
                            ans=min(ans,abs(u-i)+abs(v-j))      #计算最小曼哈顿距离
                        flag=True
                    elif A[x][y]==1:
                        g(x,y)
                    b.add((x,y))        #加入岛2边缘集合
            
        t=True
        for i in range(m):
            for j in range(n):
                if A[i][j]==1:
                    if t:
                        f(i,j)      #第一次深搜
                        t=False
                    else:
                        g(i,j)      #第二次深搜
                        return ans-1
```
