![image.png](https://pic.leetcode-cn.com/c1a534073cbbcc2309be5da8348c33360078e12402f0fb7419b26b1571e28dbd-image.png)


```
'''
单源最短路求id对应节点到所有邻接点的最短距离，
然后选出来最短距离是level的邻居节点，把这些
邻接节点观看的电影选出来计数，然后排序输出结果
'''

from typing import List
from queue import Queue
from collections import Counter
class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        que = Queue()
        que.put((id, 0))
        id2min_dist = {id : 0}

        while not que.empty():
            cur_id, cur_len = que.get()

            for next in friends[cur_id]:
                if next not in id2min_dist or cur_len + 1 < id2min_dist[next]:
                    id2min_dist[next] = cur_len + 1
                    que.put((next, cur_len+1))

        c = Counter()
        for f in [f for f in id2min_dist.keys() if id2min_dist[f] == level]:
            for v in watchedVideos[f]:
                c[v] += 1

        l = [(v, k) for k, v in c.items()]
        l.sort()
        return [x[1] for x in l]
```
