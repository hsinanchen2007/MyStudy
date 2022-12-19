遍历邻接矩阵的时间是$O({N}^{2})$，但在整个遍历过程中，修改集合指向的操作，也就是第三重循环$k$层里的操作次数应该属于并查集的正常操作次数，阿克曼函数的反函数计算，总操作最大在$O(NlogN)$级别。

```python []
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        n = len(M)
        p = {i: {i} for i in range(n)}  #并查集初始化
        ans = n
        for i in range(n):
            for j in range(i, n):       #遍历邻接矩阵
                if M[i][j] == 1 and p[i] is not p[j]:
                    p[i] |= p[j]        #集合合并
                    for k in p[j]:      #改变被合并的集合内元素指向
                        p[k] = p[i]
                    ans -= 1            #减少朋友圈
        return ans
```

这个方法是上个月想到的，今晚回看发现列表也能实现，用集合完全多余了，就改了列表版，理论上内存应该会小点，列表拼接也比集合取并集要更快些，不过提交的时候时间差距并不显著就是了，空间复杂度依旧是$O(N)$，另外在遍历迭代器上搞了点奇技淫巧。

```python []
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        n = len(M)
        p = [[i] for i in range(n)]
        ans = n
        for i, j in itertools.combinations(range(n), 2):
            if M[i][j] == 1 and p[i] is not p[j]:
                p[i] += p[j]
                for k in p[j]:
                    p[k] = p[i]
                ans -= 1
        return ans
```
