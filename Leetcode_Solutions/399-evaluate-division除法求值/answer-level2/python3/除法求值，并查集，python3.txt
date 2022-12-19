### 解题思路

![除法求值.png](https://pic.leetcode-cn.com/be0d597b754fdfb06fd14f9fe5b5da71b600ba476d0e7a2c151e15b404511a8a-%E9%99%A4%E6%B3%95%E6%B1%82%E5%80%BC.png)

我们可以将equations和values视作一个图的描述：equations代表边之间的关联，values代表边的权值
由题意我们可以知道点和点之间是双向关联，对应边的权值互为倒数

按照并查集的思路：
1. 我们先定义一个word集合确定图中一共有多少个点
2. 用parent字典初始化图中每一个点的根节点
3. 用rank字典初始化图中每一个点的根节点在树形结构中的高度

- 定义find函数，寻找节点的根节点
1. 与普通并查集一样，如果当前节点的父节点是节点本身，则返回这个节点；否则返回父节点的父节点

- 定义union函数，将x, y节点进行合并
1. 首先用find函数找到x节点的根节点xroot，y节点的根节点yroot
2. 如果xroot不等于yroot，比较一下x和y有没有父节点；如果x有父节点，就把y的父节点设为x，否则将x的父节点设为y。**（一般并查集是合并两个点的父节点，这里我们直接合并两个点，这样就可以使得图中边的两个端点，在parent集合中具有直接关联，为后面方便查询做准备。）**

- 定义union_find函数
1. 遍历equations，将点两两union
2. 将equations和values合并成一个字典，以方便查询已知条件
3. 我们新定义一个find2函数。区别于find函数，find2函数不仅可以查询当前节点的根节点，还可以查询当前节点除以根节点所得到的商。设当前节点为cur，cur的根节点是curroot，则find2最后返回的值是curroot和cur/curroot
4. 最后我们遍历queries：`for q in queries`
    设q中的两个节点分别为a，b
    如果a或b是图中没有的节点，直接在res中添加-1，continue
    如果a和b的根节点不一样，直接在res中添加-1，continue
    如果a和b的根节点是一样的，在res中添加(a/aroot)/(b/broot)即a/b
### 代码

```python3
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        word = set()
        for i in equations:
            word.add(i[0])
            word.add(i[1])
        word = list(word)
        parent = {i:i for i in word}
        rank = {i:0 for i in word}

        def find(x):
            if parent[x] == x:
                return x
            return find(parent[x])
        
        def union(x, y):
            xroot = find(x)
            yroot = find(y)
            if xroot != yroot:
                if rank[xroot] > rank[yroot]:
                    parent[y] = x
                elif rank[yroot] > rank[xroot]:
                    parent[x] = y
                else:
                    parent[x] = y
                    rank[yroot] += 1


        def union_find():
            for pair in equations:
                union(pair[0], pair[1])
            
            equ_dic={}
            for i in range(len(equations)):
                equ_dic[equations[i][0]+'#'+equations[i][1]] = values[i]
                equations[i].reverse()
                equ_dic[equations[i][0]+'#'+equations[i][1]] = 1/values[i]

            res = []

            def find2(x, d):
                if parent[x] == x:
                    return x, d
                try:
                    return find2(parent[x], d*equ_dic[x+'#'+parent[x]])
                except KeyError as e:
                    return find2(parent[x], d*equ_dic[parent[x]+'#'+x])
            
            for q in queries:
                if q[0] not in word or q[1] not in word:
                    res.append(-1)
                    continue
                aroot, d1 = find2(q[0], 1)
                broot, d2 = find2(q[1], 1)
                if aroot != broot:
                    res.append(-1)
                    continue
                res.append(d1/d2)
            return res
                
        return union_find()
```