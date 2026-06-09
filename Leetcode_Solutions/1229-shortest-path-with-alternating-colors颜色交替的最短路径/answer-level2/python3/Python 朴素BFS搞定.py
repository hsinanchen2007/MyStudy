![image.png](https://pic.leetcode-cn.com/9819684921623ddc18d4d4e520fab7f4479441b9c81fc5431c4eed075935fb46-image.png)


```
from typing import List
from queue import Queue
class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        # 邻接表构建
        r_link, b_link = {}, {}
        for s, e in red_edges:
            if s not in r_link:
                r_link[s] = []
            r_link[s].append(e)

        for s, e in blue_edges:
            if s not in b_link:
                b_link[s] = []
            b_link[s].append(e)

        ans = [-1 for _ in range(n)]
        que = Queue()
        que.put((0, 'R', 0))    # 状态定义 (位置，前一条边的颜色，到达该状态的开销)
        que.put((0, 'B', 0))
        best_state = {(0,'R'):0, (0,'B'):0}  # 最佳状态，键是(位置，前一条边的颜色)二元组，值是到达该状态的最短路径长度

        while not que.empty():
            cur_pos, prev_color, path_len = que.get()
            if prev_color == 'R' and cur_pos in b_link:
                for next_pos in b_link[cur_pos]:
                    if (next_pos, 'B') not in best_state or path_len + 1 < best_state[(next_pos, 'B')]:
                        best_state[(next_pos, 'B')] = path_len + 1
                        que.put((next_pos, 'B', path_len+1))

            if prev_color == 'B' and cur_pos in r_link:
                for next_pos in r_link[cur_pos]:
                    if (next_pos, 'R') not in best_state or path_len + 1 < best_state[(next_pos, 'R')]:
                        best_state[(next_pos, 'R')] = path_len + 1
                        que.put((next_pos, 'R', path_len+1))

        for stat, path_len in best_state.items():
            pos = stat[0]

            if ans[pos] == -1:
                ans[pos] = path_len
            else:
                ans[pos] = min(ans[pos], path_len)

        return ans

```
