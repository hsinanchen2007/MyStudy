### 解题思路
1. 贪心：每天都选择当天能参加的所有活动中，结束日期最早的那一个
2. 优先队列：将每天能参加的所有活动，按照结束时间从小到大，整理成一个优先队列，每天将队头取出
3. 哈希表：将所有活动按照开始时间散列到一个哈希表中，每天都将当天能参加的活动插入优先队列中

### 复杂度
1. 时间：`O(S*log(N)+N)`=建立哈希表`O(N)`+优先队列`O(S*log(N))`，其中`S`为同一天内存在的最大活动数
2. 空间：`O(S+N)`

### 代码

```python3
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        # ht[i] : List[int] - 所有在第i天开始的活动的结束日期
        ht, ans, maxEnd = [[] for i in range(100001)], 0, 0
        for e in events:
            ht[e[0]].append(e[1])
            maxEnd = max(maxEnd, e[1])
        # q : List[int] - 所有当前可以参加的活动的结束日期
        q = []
        for i in range(1, maxEnd+1):
            # 在第i天，那些于第i天开始的活动可以被加入q中
            for e in ht[i]:
                heapq.heappush(q, e)
            # 选取一个结束时间最早的活动
            if len(q) != 0:
                heapq.heappop(q)
                ans += 1
                # 把所有结束时间<=i（也就是过了今天就不能再参加）的活动从q中移除
                while len(q):
                    e = heapq.heappop(q)
                    if e > i:
                        heapq.heappush(q, e)
                        break
        return ans
```