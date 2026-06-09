### 解题思路
典型的BFS。先找到l层的朋友，然后记录这一层朋友看过的视频以及次数，最后输出排序后的结果。
### 代码

```python
class Solution:
    def watchedVideosByFriends(self, watchedVideos, friends, id, level):
        q, s = [id], []
        seen, l = set(q), 0
        while q:
            if l == level: break
            while q:
                person = q.pop(0)
                for w in friends[person]:
                    if w not in seen:
                        seen.add(w)
                        s.append(w)
            q, s = s, q
            l +=1
        dic = {}
        for w in q:
            for v in watchedVideos[w]:
                dic[v] = dic.get(v, 0) + 1
        return sorted(dic.keys(), key = lambda x: (dic[x], x))
```