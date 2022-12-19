### 解题思路
这里是powcai大佬的代码，我主要是理解了这份代码：预处理+BFS，预处理是把连续相同的元素只保留前后两个索引，BFS的终止条件就是就是当前为所寻结点，每一层（queue每次保留一层结点）遍历结束后，step+1.

### 代码

```python3
class Solution:
    def minJumps(self, arr: List[int]) -> int:
        from collections import defaultdict
        from collections import  deque
        loc = defaultdict(list)
        # 只记录首尾位置
        for idx, val in enumerate(arr):
            if len(loc[val]) > 1 and loc[val][-1] + 1 == idx:
                loc[val].pop()
            loc[val].append(idx)
        visited = {0}
        queue = deque([0])
        step = 0
        l = len(arr)
        while queue:
            n = len(queue)
           # print(visited)
            for i in range(n):
                idx = queue.pop()
                if idx == l - 1:
                    return step
                for j in [idx - 1, idx + 1] + loc[arr[idx]]:
                    if 0 <= j < l and j not in visited:
                        visited.add(j)
                        queue.appendleft(j)
            step += 1
```