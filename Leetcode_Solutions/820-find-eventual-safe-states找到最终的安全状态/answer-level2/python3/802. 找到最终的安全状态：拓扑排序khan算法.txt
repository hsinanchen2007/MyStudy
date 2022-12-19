实质也算宽搜，从零出度的元素初始化队列，这些点就是安全点，逐个删除入度到这些零出度点的边，这样又会产生一些零出度的点，继续加入队列，直到处理完队列不能继续加入点为止，未加入的点，则说明存在环，不符合输出的要求。

找到每个点的入度，需要对图的邻接表进行一次逆方向处理，处理成入度表。

时间复杂度，逆邻接表处理需要遍历所有的边$O(E)$，队列处理删除关系$O(E)$，最后对点进行排序$O(NlogN)$，总体为$O(2E+NlogN)$，额外空间为$O(E+N)$。

```python []
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        ans = []
        ind = collections.defaultdict(list) #入度表
        for i in range(len(graph)):
            if not graph[i]:        #无出度的加入输出
                ans += [i]
            for j in graph[i]:      #生成入度表
                ind[j] += [i]
        for j in ans:               #遍历无出度点
            for i in ind[j]:        #遍历该点的入度点
                graph[i].remove(j)  #删除出度
                if not graph[i]:    #如果没有出度了
                    ans += [i]      #加入输出
        return sorted(ans)
```

或者只维护出度的边数，可以只计数不删边，时间上加了个$O(N)$，但影响不大，OI操作上能快一点，不过空间也多了$O(N)$。

```python [1]
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        ans = []
        oud = [*map(len, graph)]    #出度数统计
        ind = collections.defaultdict(list) #入度表
        for i in range(len(graph)):
            if oud[i] == 0:         #无出度的加入输出
                ans += [i]
            for j in graph[i]:      #生成入度表
                ind[j] += [i]
        for j in ans:
            for i in ind[j]:        #遍历该点的入度点
                oud[i] -= 1         #出度数减一
                if oud[i] == 0:     #如果没有出度了
                    ans += [i]      #加入输出
        return sorted(ans)
```
