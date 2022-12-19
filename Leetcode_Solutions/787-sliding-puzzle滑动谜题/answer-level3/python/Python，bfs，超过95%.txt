常规bfs题，需要注意的一点是，字符串和tuple都可以用来哈希，但tuple的哈希速度更快
```python
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        board = board[0]+board[1]  # 把board连起来变一维
        moves = [(1, 3), (0, 2, 4), (1, 5), (0, 4), (1, 3, 5), (2, 4)]  # 每个位置的0可以交换的位置
        q, visited = [(tuple(board), board.index(0), 0)], set()  # bfs队列和已访问状态记录
        while q:
            state, now, step = q.pop(0)  # 分别代表当前状态，0的当前位置和当前步数
            if state == (1, 2, 3, 4, 5, 0):  # 找到了
                return step
            for next in moves[now]:  # 遍历所有可交换位置
                _state = list(state)
                _state[next], _state[now] = _state[now], state[next]  # 交换位置
                _state = tuple(_state)
                if _state not in visited:  # 确认未访问
                    q.append((_state, next, step+1))
            visited.add(state)
        return -1
```

附上dfs的剪枝解法，在这道题里肯定不如bfs快，但可以参考思路以应对合适的题
```python
    def slidingPuzzle(self, board: list) -> int:
        def dfs(state, now, visited):  # state当前状态，now为0所处位置，visited为遍历过的状态
            if len(visited) < _min.get(state, 720):  # 剪枝
                _min[state] = len(visited)
                for next in moves[now]:  # 尝试每一个可交换的位置
                    _state = list(state)
                    _state[next], _state[now] = _state[now], state[next]  # 交换位置
                    _state = tuple(_state)
                    if _state not in visited:  # 未访问
                        dfs(_state, next, visited | {state})

        board, _min = board[0]+board[1], {}  # 把board连起来变一维，_min记录达到每个状态的当前最短路径
        moves = [(1, 3), (0, 2, 4), (1, 5), (0, 4), (1, 3, 5), (2, 4)]  # 每个位置的0可以交换的位置
        dfs(tuple(board), board.index(0), set())  # 从起始状态开始dfs
        return _min.get((1, 2, 3, 4, 5, 0), -1)

```
