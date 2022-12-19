```python
class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        fri_dic = collections.defaultdict(list)
        for index, fris in enumerate(friends):
            for fri in fris: fri_dic[index].append(fri)
        
        res_dic = collections.defaultdict(int)
        queue = [(id, 0)]
        visited = set([id])
        while queue != []:
            node, layer = queue.pop()
            if layer == level:
                for video in watchedVideos[node]:
                    res_dic[video] += 1
                continue
            for fri in fri_dic[node]:
                if fri not in visited:
                    visited.add(fri)
                    queue.append((fri, layer + 1))
        res = sorted(res_dic.items(), key = lambda x : (x[1], x[0]))
        return  [x[0] for x in res]

```