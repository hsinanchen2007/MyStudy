
队列存的是 `[当前员工索引, 当前员工完成通知这一任务经过的时间]`
每次出队的时候, 记录一下截止目前为止的最大时间即可.

```python
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        que = collections.deque()
        res = 0
        n = len(manager)
        cnt = 1
        que.append((headID, informTime[headID]))
        id_with_idxs = {}
        for idx, val in enumerate(manager):
            if val not in id_with_idxs:
                id_with_idxs[val] = [idx]
            else:
                id_with_idxs[val].append(idx)
        while que:
            cur_id, cur_time = que.popleft()
            res = max(res, cur_time)
            if cur_id in id_with_idxs:
                for idx in id_with_idxs[cur_id]:
                    que.append((idx, cur_time + informTime[idx]))
        return res
```