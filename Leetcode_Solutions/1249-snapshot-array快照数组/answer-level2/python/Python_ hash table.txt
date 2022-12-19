### 解题思路
把数组存在一个包含 n 个 hash table 的 list。每一个 hash table 里面的 key 表示 snap_id，value 表示在该 snap_id 时候的 val。

每次更新数组的时候，只更新相应的 index，key 为当前的`snap_id + 1`。

当需要读取的时候，首先查看 snap_id 是否在 hash table 里，如果存在，直接返回所在的val；如果不在，说明在此 snap 时没有并没有更新 val，那么我们只要找到之前一个 snap 即可。

### 代码

```python
class SnapshotArray:

    def __init__(self, n: int):
        self.arr = [{-1:0} for _ in range(n)]
        self.s = -1
        
    def set(self, index: int, val: int) -> None:
        self.arr[index][self.s + 1] = val

    def snap(self) -> int:
        self.s +=1
        return self.s

    def get(self, index: int, snap_id: int) -> int:
        if snap_id in self.arr[index]:
            return self.arr[index][snap_id]
        prev = max([i for i in self.arr[index].keys() if i < snap_id])
        return self.arr[index][prev]
```