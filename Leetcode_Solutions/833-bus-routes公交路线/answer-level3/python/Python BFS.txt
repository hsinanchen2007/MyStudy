先统计所有的站台能等到哪些公交车,然后利用队列开始BFS搜索
参考了bilibili上花花酱的视频中c++代码
时间不是很快
```python
import queue
class Solution:
    def numBusesToDestination(self, routes: List[List[int]], S: int, T: int) -> int:
        if S == T: return 0
        m = {}
        q = queue.Queue()
        for i in range(len(routes)):
            for stop in routes[i]:
                if stop in m:
                    m[stop].append(i)
                else:
                    m[stop] = [i]
        # print(m)
        taken = [0] * len(routes)
        buses = 0
        q.put(S)
        while not q.empty():
            size = q.qsize()
            buses += 1
            while size:
                size -= 1
                cur_stop = q.get()
                for bus in m[cur_stop]:
                    if taken[bus]: continue
                    taken[bus] = 1
                    for stop in routes[bus]:
                        if stop == T: return buses
                        q.put(stop)
                        # print(stop)
        return -1
```