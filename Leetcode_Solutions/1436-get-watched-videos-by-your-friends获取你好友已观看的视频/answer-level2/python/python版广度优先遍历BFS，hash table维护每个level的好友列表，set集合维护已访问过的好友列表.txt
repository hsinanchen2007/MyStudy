主要思路：
1. 用一个hash table(python里的字典)维护每个level的好友列表，即level->friends ids 的映射
2. 由于题目要求最短距离为 k 的好友观看过的视频，因此在前面level出现过的好友不能出现在后面任一level，否则就不是距离最短了，因此用一个集合set记录一个已访问的visited好友列表，用set是因为其具有常数的时间复杂度，便于查找。
3. 题目要求频率相同的视频，将它们按名字字典序从小到大排列，因此最后需要将查询结果先按频次排序，在频次基础上再按字典序排序。

代码如下：

```
class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        friendlevs=dict()
        friendlevs[0]=[id]
        visited={id}
        for l in range(1,level+1):
            for i in friendlevs[l-1]:
                for p in friends[i]:
                    if not p in visited:
                        if not l in friendlevs:
                            friendlevs[l]=[p]
                        else:
                            friendlevs[l].append(p)
                        visited.add(p)
        if not level in friendlevs:
             return None
        givenfriends=friendlevs[level]
        fvideos=dict()
        for f in givenfriends:
            for v in watchedVideos[f]:
                if not v in fvideos:
                    fvideos[v]=1
                else:
                    fvideos[v]+=1
        fvideos=list(fvideos.items())
        fvideos=sorted(fvideos,key=lambda x:(x[1],x[0]))
        for k in range(len(fvideos)):
            fvideos[k]=fvideos[k][0]
        return fvideos
```
