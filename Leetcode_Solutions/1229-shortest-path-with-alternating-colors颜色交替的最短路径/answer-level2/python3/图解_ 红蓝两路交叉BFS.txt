- main idea：BFS，从节点0起，每次take one step，这样保证到达每个节点时路径是最短的。而我们并不知道节点0到达节点i的最短路径，是'红蓝红...'还是'蓝红蓝...'，所以我们需要都找出来，用nx2的数组`dist`保存，最后再选短的那个。

<![IMG_0249.PNG](https://pic.leetcode-cn.com/5d14553a3eeaf0a79939af5102f11748a7b0a5b0384a3418d9c6054ea4e4e39b-IMG_0249.PNG),![IMG_0251.PNG](https://pic.leetcode-cn.com/56c80ba067a56c5d8be6f45c14beb3a23f4e6eb7e0d1b9de113bed322575d6a4-IMG_0251.PNG),![IMG_0255.PNG](https://pic.leetcode-cn.com/d6c1cb376aabd6333f3640b6ad6854e9e948c6eb0b6678daf3ae4c54768ba3e8-IMG_0255.PNG),![IMG_0253.PNG](https://pic.leetcode-cn.com/241c86aabee75c537a7a154f07606b4af479323e684c0c7f942a82e70da524b5-IMG_0253.PNG),![IMG_0254.PNG](https://pic.leetcode-cn.com/c37a030e1a5570ababd497f804ada161063db4e94a2405c051e3ce987b58576d-IMG_0254.PNG)>


```python []
class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        red_path = [set() for i in range(n)]
        blue_path = [set() for i in range(n)]
        dist = [[None, None] for i in range(n)]
        dist[0] = [0, 0]
        step = 0
        now_red = [0]
        now_blue = [0]
        for start, end in red_edges:
            red_path[start].add(end)
        for start, end in blue_edges:
            blue_path[start].add(end)
        # step 1 找到分别以红边开始和以蓝边开始的两条最短路径
        while len(now_red) != 0 or len(now_blue) != 0 :
            new_red, new_blue = [], []
            step += 1
            if len(now_blue) != 0:
                for point in now_blue:
                    for next_point in red_path[point]:
                        if dist[next_point][0] is None:
                            new_red.append(next_point)
                            dist[next_point][0] = step
            if len(now_red) != 0:
                for point in now_red:
                    for next_point in blue_path[point]:
                        if dist[next_point][1] is None:
                            new_blue.append(next_point)
                            dist[next_point][1] = step
            now_red, now_blue = new_red, new_blue
        # step 2 在这两条最短路径中选择小的，merge成我们的答案
        ans = []
        for i in range(n):
            if dist[i][0] is None and dist[i][1] is None:
                ans.append(-1)
            elif dist[i][0] is not None and dist[i][1] is not None:
                ans.append(min(dist[i][0], dist[i][1]))
            elif dist[i][0] is not None:
                ans.append(dist[i][0])
            else:
                ans.append(dist[i][1])
        return ans
```