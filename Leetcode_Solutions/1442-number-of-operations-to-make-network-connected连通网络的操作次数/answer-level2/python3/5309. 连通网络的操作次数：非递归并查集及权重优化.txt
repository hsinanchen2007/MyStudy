### 解题思路

注意判断`len(connections) < n - 1`时直接返回`-1`就行

### 传统并查集模板

```python []
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        p = [*range(n)]
        def f(x):
            if p[x] != x:
                p[x] = f(p[x])
            return p[x]
        for x, y in connections:
            p[f(y)] = f(x)
        return len({*map(f, p)}) - 1
```

### 非递归并查集

空间复杂度看似很大，实际上`p`内的元素都是数组引用，每次操作完成后实际数组的总长度仍然是`n`，算上临时内存最大也不会超过`1.5 * n`（即所有元素合并成两个同长数组，最后再合并成一个数组时达到最大临时内存），并且在每个循环单元结束后都覆盖掉原空间，总大小又恢复成`n`，比传统函数法空间略大，但仅是大在了创建了`n`个数组的开销，空间复杂度是没有变量级的差距的，只有常数级的差距，所以空间复杂度依旧是$O(N)$，线上测试与传统法的内存消耗也看不出太大差别。

时间复杂度上与传统法一致，但省去了递归函数栈的创建与销毁的时空开销，线下测试过比传统法略快一点点。

```python []
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        p = [[i] for i in range(n)]
        for x, y in connections:
            if p[x] is not p[y]:
                p[x].extend(p[y])
                for z in p[y]:
                    p[z] = p[x]
        return len({*map(id, p)}) - 1
```

### 非递归并查集的权重优化

一个判断即可实现并查集权重优化，即令小集合优先并入大集合，减少集合合并时的变更操作，比传统法的权重优化更加简洁清晰。

```python []
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        p = [[i] for i in range(n)]
        for x, y in connections:
            if p[x] is not p[y]:
                if len(p[x]) < len(p[y]):
                    x, y = y, x
                p[x].extend(p[y])
                for z in p[y]:
                    p[z] = p[x]
        return len({*map(id, p)}) - 1
```

![image.png](https://pic.leetcode-cn.com/45ccae402f6515bf3daae0160320c3887af27dc11181cea16d89af622b0ac33f-image.png)
