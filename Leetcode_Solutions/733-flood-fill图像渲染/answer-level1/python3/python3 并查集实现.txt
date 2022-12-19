### 解题思路
一、首先定义UnionFind类，通过数组实现，用pre变量表示，其中pre[i]=j表示i的上级是j。
初始化时令pre[i]=i，表示每个元素的上级是自己，即互不连通。
内部有三个函数：
    find(x)指找到x的最上级，在查找过程中不断将当前x的上级更新为上级的上级，直到找到最上级为止；
    union(x,y)指将x,y合并，即令其中一方成为另一方的上级；
    connect(x,y)用来判断二者的连通性，若二者上级相同，则视为二者已经连通。

二、创建UnionFind类对象 UnionFind(mn)，m为行数，n为列数；并将二维坐标映射为一维数组，即[i,j] --> i*n+j
共遍历两遍image，第一次遍历时将所有像素相同的点连通，结果记录在pre数组中；
第二次遍历，将所有与初始坐标连通的点的像素值改为newColor。


### 代码

```python3
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        m=len(image)
        n=len(image[0])
        uf=UnionFind(m*n)
        for i in range(m):
            for j in range(n):
                right=j+1
                down=i+1
                if right < n and image[i][j]==image[i][right]:
                    uf.union(i*n+j,i*n+right)
                if down < m and image[i][j]==image[down][j]:
                    uf.union(i*n+j,down*n+j)
        for i in range(m):
            for j in range(n):
                if uf.connect(i*n+j,sr*n+sc):
                    image[i][j]=newColor
        return image
            
class UnionFind:
    def __init__(self,n):
        self.pre=[i for i in range(n)]

    def find(self,x):
        while x!=self.pre[x]:
            self.pre[x]=self.pre[self.pre[x]]
            x=self.pre[x]
        return x

    def union(self,x,y):
        x=self.find(x)
        y=self.find(y)
        if x!=y:
            self.pre[y]=x
            
    def connect(self,x,y):
        return self.find(x)==self.find(y)
```