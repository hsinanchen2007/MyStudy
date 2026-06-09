```python []
class Solution:
    def isEscapePossible(self, blocked, source, target) -> bool:
        tmp = blocked+[source]+[target]
        m = sorted([i for i,_ in tmp])   #高
        n = sorted([i for _,i in tmp])   #宽
        hash_d_m,hash_d_n={},{}
        #分别对横纵坐标压缩地图，建立实际坐标,映射坐标的字典
        index,pre=-1,-1
        for i in m:
            if hash_d_m.get(i,-1)==-1:
                index = index+1 if i==pre+1 else index+2        #上一行相邻的时候hash相邻 否则中间要插入一行
                hash_d_m[i]=index
                pre=i
        m_max = index
        index,pre=-1,-1
        for i in n:
            if hash_d_n.get(i,-1)==-1:
                index = index+1 if i==pre+1 else index+2        #上一行相邻的时候hash相邻 否则中间要插入一行
                hash_d_n[i]=index
                pre=i
        n_max = index
        #正常bfs,注意坐标使用压缩后的坐标，转换方法就是字典
        q={(hash_d_m[source[0]],hash_d_n[source[1]])}
        blocked = set(map(lambda x:(hash_d_m[x[0]],hash_d_n[x[1]]),blocked))
        while q:
            s=set()
            for i,j in q:
                if i==hash_d_m[target[0]] and j==hash_d_n[target[1]]:return True
                for row,col in ((i,j+1),(i,j-1),(i+1,j),(i-1,j)):
                    if 0<=row<=m_max and 0<=col<=n_max and (row,col) not in blocked:
                        s.add((row,col))
                        blocked.add((row,col))
            q=s
        return False
```


