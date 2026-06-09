### 解题思路
基于列表BFS+排序小技巧
三个步骤
第一部分
按照层级取。利用队列层次遍历列表(BFS)
```
levelf=[]
        q=[]
        q.append(friends[id])
        count=1
        visit=set()
        visit.add(id)
        while q:
            t = q.pop(0)
            if count==level:
                for i in t:
                    if i in visit:
                        continue
                    levelf.append(i)
                break   
            tempf=[]            
            for i in t:
                if i in visit:
                    continue
                visit.add(i)
                tempf.extend(friends[i])
            q.append(tempf)
            count=count+1
```
第二部分 数据处理
去掉起始节点
```
levelf=list(set(levelf))
        if id in levelf:
            levelf.remove(id)
```

第三部分 遍历电影+keyvalue排序
```
d=collections.defaultdict()
        for i in levelf:
            for j in watchedVideos[i]:
                if j in d:
                    d[j]+=1
                else:
                    d[j]=0
        c=sorted(d.items(), key=lambda kv: (kv[1], kv[0]))
        return [x for x,_ in c]
```

### 代码

```python3
class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        levelf=[]
        q=[]
        q.append(friends[id])
        count=1
        visit=set()
        visit.add(id)
        while q:
            t = q.pop(0)
            if count==level:
                for i in t:
                    if i in visit:
                        continue
                    levelf.append(i)
                break   
            tempf=[]            
            for i in t:
                if i in visit:
                    continue
                visit.add(i)
                tempf.extend(friends[i])
            q.append(tempf)
            count=count+1
        levelf=list(set(levelf))
        if id in levelf:
            levelf.remove(id)
        d=collections.defaultdict()
        for i in levelf:
            for j in watchedVideos[i]:
                if j in d:
                    d[j]+=1
                else:
                    d[j]=0
        c=sorted(d.items(), key=lambda kv: (kv[1], kv[0]))
        return [x for x,_ in c]
```