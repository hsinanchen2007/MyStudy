来个新颖的解法：

举例【5，0，3，8，6】的索引按值排序后为【1，2，0，4，3】，那么扫描【1，2，0，4，3】扫描到【0】时其前面（包含0）的数为所有【0-2】，那么在这里分割就是答案了。

扫描时这里的判断我为了省事直接用的哈希就过了，当然也可以优化为更有效率的办法，

```python
    def partitionDisjoint(self, A: list) -> int:
        index_sorted = [i for (v, i) in sorted(zip(A, range(len(A))))]
        i_ori, i_now = set(), set()
        for (i, v) in enumerate(index_sorted):
            i_now.add(i)
            i_ori.add(v)
            if i_now == i_ori:
                return i+1
```
