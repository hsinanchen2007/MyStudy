![image.png](https://pic.leetcode-cn.com/fd2b17ca3080a316feb83dcd5bdbf101bd18a9ab7aaf34f91741e73ec1a370ca-image.png)

比起算法，更像是语法讲解。


**dfs:**


原理就没啥可说的，就是以`0`点为起点深度优先遍历，通过`vst`来记录访问过的节点，如果访问了全部节点就返回`True`。

另外要提的一点是虽然集合运算的 `vst |= {key}` 和 `vst.add(key)` 在效率上已经优化到基本一致，但在函数内，只有使用`add`才会默认`vst`是全局对象，用 `|=` 需要另外声明`nonlocal vst` 或者使用全局变量 `self.vst`。

```python []
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        vst = set()
        def f(key):
            vst.add(key)  
            [f(k) for k in rooms[key] if k not in vst]
        return f(0) or len(vst) == len(rooms)
```


**bfs:**

原理就是`0`为起点，对队列`que`进行宽度优先遍历，通过`vst`来记录访问过的节点，如果访问了全部节点就返回`True`。

Python的遍历特性决定了可以通过`for`来直接遍历，减少`.pop(0)`这种操作，而且由于不在函数内执行，所以列表和集合运算可以直接用 `+=` 和 `|=` 。

```python []
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        que, vst = [0], {0}
        for key in que:
            for k in filter(lambda k: k not in vst, rooms[key]):
                que += [k]
                vst |= {k}
        return len(vst) == len(rooms)
```

两个方法的时间复杂度都是$O(E)$，其中$E$为钥匙关系总数，实际运行也相差不大，不过最快速度是dfs跑出来的，bfs目前最快76ms这样。