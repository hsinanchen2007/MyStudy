A*，BFS搜索的时候根据估价函数，优先搜索优先级高的节点。

跟BidirectionalBFS一样，从起点和终点同时搜索，搜索到重合的地方就等于找到了最短路劲，然后返回两点的距离和。

``` python3
import itertools
from heapq import heappush, heappop
from typing import List

class Node:

    def __init__(self, state, parent=None, h=0):
        self.state = state
        self.parent = parent
        self.g = parent.g + 1 if parent else 0
        self.h = h
        self.f = self.g + self.h
        self.zero = state.index(0)

    def __lt__(self, other):
        return self.f < other.f


class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        R, C = len(board), len(board[0])
        start = tuple(itertools.chain(*board))
        n = R * C
        goal_pos = {(C * r + c + 1) % (R * C): (r, c) for r in range(R) for c in range(C)}
        start_pos = {start[C * r + c]: (r, c) for r in range(R) for c in range(C)}

        target = tuple((i + 1) % n for i in range(n))

        def heuristic(start, target_pos):
            res = 0
            for r in range(R):
                for c in range(C):
                    val = start[c + r * C]
                    if val == 0: continue
                    res += abs(r - target_pos[val][0]) + abs(c - target_pos[val][1])
            return res

        bq, eq, rev = [Node(start, h=0)], [
            Node(target, h=0)], False
        b_scores = {start: bq[0]}
        e_scores = {target: eq[0]}
        count = 0
        while bq:
            size = len(bq)
            while size:
                size -= 1
                node = heappop(bq)
                count += 1
                f, g, board, zero = node.f, node.g, node.state, node.zero
                if b_scores[board].f < node.f: continue
                if board in e_scores:
                    return node.g + e_scores.get(board).g
                for nei in [nei for nei in [1 + zero, -1 + zero, C + zero, -C + zero] if
                            abs(nei // C - zero // C) + abs(nei % C - zero % C) == 1 and 0 <= nei < n]:
                    new_board = list(board)
                    new_board[nei], new_board[zero] = new_board[zero], new_board[nei]
                    new_board = tuple(new_board)
                    nn = Node(new_board, node, heuristic(new_board, goal_pos))
                    if nn.f < b_scores.get(new_board, Node(new_board, h=float('inf'))).f:
                        heappush(bq, nn)
                        b_scores[new_board] = nn
            if len(bq) > len(eq):
                bq, eq, b_scores, e_scores, goal_pos, start_pos, rev = eq, bq, e_scores, b_scores, start_pos, goal_pos, not rev
        return -1
```
