首先尝试用单向BFS，果不其然超时了。。。用上双向BFS就能过了。

**要点**：
- 用哈希表记录相同value的位置，为了后面方便跳跃
- 用visited记录每个位置是否被搜索过
- 用两个队列进行BFS，从前往后和从后往前，一层一层搜索，当两个方向的搜索碰到了，就停止
- 搜索的时候，检查左右两个位置以及哈希表中可跳跃的位置，是否在另一个队列中，以及是否被搜索过，否的话加入队列中

（ps. 两个方向的搜索可以再合并，代码可以简洁一些）

```
from queue import Queue
class Solution:
    def minJumps(self, arr: List[int]) -> int:
        if len(arr) == 1: return 0
        
        # use a HashTable to record the indexes of same values
        d = {}
        for i in range(len(arr)):
            if arr[i] not in d.keys():
                d[arr[i]] = [i]
            else:
                d[arr[i]].append(i)
        
        visited = [False] * len(arr)
        visited[0] = True
        res = 0
        succ = False
        n_next1, n_next2 = 1, 1

        q1 = Queue()
        q1.put(0)
        q2 = Queue()
        q2.put(len(arr) - 1)

        while q1.qsize() != 0 and q2.qsize() != 0:   

            # first direction, from start to end        
            n_layer = 0
            for k in range(n_next1):
                pop = q1.get()
                
                if pop != 0:
                    if pop - 1 in q2.queue:
                        succ = True
                        break
                    if not visited[pop - 1]:
                        q1.put(pop - 1)
                        visited[pop - 1] = True
                        n_layer += 1

                if pop != len(arr) - 1: 
                    if pop + 1 in q2.queue:
                        succ = True
                        break
                    if not visited[pop + 1]:
                        q1.put(pop + 1)
                        visited[pop + 1] = True
                        n_layer += 1
                    
                if len(d[arr[pop]]) != 1:
                    for i in reversed(d[arr[pop]]):
                        if i in q2.queue:
                            succ = True
                            break
                        if not visited[i]: 
                            q1.put(i)
                            visited[i] = True
                            n_layer += 1
            
            if succ: break
            n_next1 = n_layer
            res += 1
            
            # second direction, from end to start
            n_layer = 0
            for k in range(n_next2):
                pop = q2.get()
                    
                if pop != 0:
                    if pop - 1 in q1.queue:
                        succ = True
                        break
                    if not visited[pop - 1]:
                        q2.put(pop - 1)
                        visited[pop - 1] = True
                        n_layer += 1

                if pop != len(arr) - 1: 
                    if pop + 1 in q1.queue:
                        succ = True
                        break
                    if not visited[pop + 1]:
                        q2.put(pop + 1)
                        visited[pop + 1] = True
                        n_layer += 1
                    
                if len(d[arr[pop]]) != 1:
                    for i in reversed(d[arr[pop]]):
                        if i in q1.queue:
                            succ = True
                            break
                        if not visited[i]: 
                            q2.put(i)
                            visited[i] = True
                            n_layer += 1
                    
            if succ: break
            n_next2 = n_layer
            res += 1
                        
        return res + 1
```
