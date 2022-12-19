记录的目的是在目标行动到某一位置时，访问过的状态不能重复。

```
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n=len(graph)
        if n==1 and graph[0]==[]:
            return 0
        tar=(1<<n)-1
        ans=float('inf')
        
        def f(i):
            dic={(i,1<<i)}      #状态记录
            que={(i,1<<i)}      #宽搜队列
            tans=1      #临时步长记录
            while que:
                tmp=set()
                for j,t in que:     #que宽搜队列中，j节点，t已访问过的状态
                    for k in graph[j]:      #遍历j节点的联通点
                        p=t|(1<<k)      #对节点进行访问
                        if p==tar:      #如果全部访问，就统计最短的临时步长
                            nonlocal ans
                            ans=min(ans,tans)
                            return
                        if (k,p) not in dic:        #不进入重复的状态
                            dic|={(k,p)}
                            tmp|={(k,p)}
                que=tmp
                tans+=1
            
        for i in range(n):f(i)      #从各个节点开始走
            
        return ans
```
