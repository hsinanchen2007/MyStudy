### 解题思路
### 并查集
可以用树表示，辅以字典(列表)。（使用树的双亲表示法）
如{node:parent}
--node 0,1,2,...,n
parent 1,2,2,...,n
#### 1.查操作（findroot）:
查找根节点，并同时将当前节点挂接到根节点上（路径压缩），因此可以使用递归：
```
def findroot(x)#根节点查找--查操作
tree.setdefault(x,x)#未定义时，将自身设为父节点
if tree[x]!=x:#若父节点不为自身，则找到父节点的根节点，并将现在的节点指向根节点（路径压缩）
    tree[x]=findroot(tree[x])
return tree[x]

```
#### 2.并操作（union）:
有两个节点x,y,合并也就是把它们的根节点连接起来，先利用查操作找到各自的根节点，如果根节点不同，则连接起来。
```
def union(x,y):#集合合并--并操作(只在根节点处合并)
    if findroot(x)!=findroot(y):
        tree[findroot(x)]=findroot(y)#将y的根节点和x的根节点相连接
```
#### 3.建立树（合并集合）：
需要对grid进行遍历，每找到值为"1"的元素a，查找它的上/左方向是否还有值为1的元素b/c，若有则将a设为b/c的父节点。注意：tree用非嵌套字典表示，则需要把2维的grid中的元素索引变为1维的，即(x,y)<==>x*col+y.
#### 4.查找有几个符合条件的大集合（查找根节点）
比对树根节点是否相同<可以直接用set()>
遍历每个元素，找到值为1的各个元素的根节点

### 代码

```python3
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        #DISJOINT SET
        tree={}
        def findroot(x):#找到根节点--查操作(路径压缩，原来指向父节点现在指向根节点)
            tree.setdefault(x,x)#若之前未定义x,则将x的根节点设为自身
            #if tree[x]==x:return x#找到根节点（这样会很慢）
            #else: return findroot(tree[x])##该结点不是根节点,找父节点的根节点(这样会很慢)
            if tree[x]!=x:#若父节点不为自身，则找到父节点的根节点，并将现在的节点指向根节点（路径压缩）
                tree[x]=findroot(tree[x])
            return tree[x]
        def union(x,y):#集合合并--并操作(只在根节点处合并)
            if findroot(x)!=findroot(y):
                tree[findroot(x)]=findroot(y)#将y的根节点和x的根节点相连接
        #合并集合(树的建立)：
        if not grid:return 0#特殊情况
        row=len(grid)
        col=len(grid[0])
        for i in range(row):#遍历每个元素
            for j in range(col):
                if grid[i][j]=='1':#若发现元素为1
                    for x,y in [[-1,0],[0,-1]]:#找左/上元素
                        temp_x=i+x
                        temp_y=j+y
                        if 0<=temp_x<row and 0<=temp_y<col and grid[temp_x][temp_y]=='1':#左/上元素不出界限且依然为1
                            #左/上元素的根节点挂接到当前节点
                            union(temp_x*col+temp_y,i*col+j)#合并操作，各自根节点相连（二维按行转换为一维:(x,y)->x*col+y））
        #查找合并集合后有几个大集合#比对树根节点是否相同<可以直接用set()>
        res=set()
        for i in range(row):#遍历每个元素，找到值为1的各个元素的根节点
            for j in range(col):
                if grid[i][j]=='1':
                    res.add(findroot(i*col+j))
        return len(res)
```