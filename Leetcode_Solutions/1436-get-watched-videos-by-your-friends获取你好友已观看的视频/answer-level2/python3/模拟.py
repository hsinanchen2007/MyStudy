## 思路
1. 构建第`level`层好友列表，这里要注意记录已经访问过的好友
2. 统计该层所有好友影片
3. 根据影片观看数量升序，数量相同时影片名字典升序

## 代码
```
class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        now = 0        # 当前层数
        flag = set()   # 已经访问过的好友
        fre = set([id])# 第 now 层朋友圈
        videos = []
        '''
        1. 构建第 now 层列表
        '''
        while now < level:
            tmp = set()
            for i in fre:
                if i in flag: # 已经访问过的好友不算
                    continue
                flag.add(i)
                tmp.update(friends[i])
            fre = tmp
            now += 1
        fre = [x for x in fre if x not in flag] # 去除已经访问过的
        '''
        2. 统计好友影片数
        '''
        for f in fre:
            for v in watchedVideos[f]:
                videos.append(v)
        result = collections.defaultdict(int)
        for v in videos:
            result[v] += 1
        '''
        3. 排序输出
        '''
        c = sorted(result.items(), key=lambda x:(x[1], x[0]))
        res  = []
        for k, v in c:
            res.append(k)
        return res
```