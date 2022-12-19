### 解题思路
基于字典判断法官，法官应出度为0入度为N-1。

### 代码

```python3
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        if len(trust) == 0 and N == 1:
            return 1
        set_ = dict().fromkeys(list(i for i in range(1, N + 1)))
        for i in set_:
            set_[i] = 0
        max_, id_, count = -1, -1, 1
        for i in trust:
            set_[i[1]] += 1
            if set_[i[1]] > max_:
                count, max_, id_ = 1, set_[i[1]], i[1]
            elif set_[i[1]] == max_:
                count += 1
        return id_ if max_ == N - 1 and count == 1 and id_ not in list(trust[i][0] for i in range(len(trust))) else -1

```