### 解题思路
此处撰写解题思路
简单朴素bfs，没啥好说的
### 代码

```python3
class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        if n == 1:
            return 1
        map_tree = {}
        for edge in edges:
            if edge[0] not in map_tree.keys():
                map_tree[edge[0]] = []
            map_tree[edge[0]].append(edge[1])
            if edge[1] not in map_tree.keys():
                map_tree[edge[1]] = []
            map_tree[edge[1]].append(edge[0])
        # print(map_tree)
        is_visit = [False]*(n+1)
        site_t = [0]*(n + 1)
        site_p = [1]*(n+1)

        import queue
        store = queue.Queue()
        store.put(1)
        is_visit[1] = True
        while not store.empty():
            tmp_site = store.get()
            site_num = 0
            for site in map_tree[tmp_site]:
                if not is_visit[site]:
                    site_num += 1
            if tmp_site == target and site_num == 0 and site_t[tmp_site] <= t:
                return site_p[tmp_site]
            # print('tmp_site', tmp_site, 'site_num', site_num)
            for site in map_tree[tmp_site]:
                if not is_visit[site]:
                    store.put(site)
                    is_visit[site] = True
                    site_t[site] = site_t[tmp_site] + 1
                    site_p[site] = site_p[tmp_site]/site_num
                    if site == target and site_t[site] == t:
                        return site_p[site]
                    if site_t[site] > t:
                        return 0
        return 0

```