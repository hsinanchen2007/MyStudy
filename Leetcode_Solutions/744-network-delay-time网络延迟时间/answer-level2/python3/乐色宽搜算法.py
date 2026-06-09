慢得无法相信，提交记录里的时间平均比我快10倍，到底是用了什么神仙算法

```
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        d={}
        for i,j,k in times:
            if i not in d:
                d[i]={}
            d[i][j]=k       #目标时间哈希化
        c={K:0}     #节点时间记录
        que={K}     #宽搜队列
        che=set()
        while che!=c:       #修改检查
            che=c.copy()
            t=set()     #新增宽搜队列
            for i in que:
                if i in d:
                    for j in d[i]:
                        if j not in c:
                            c[j]=c[i]+d[i][j]
                        else:
                            c[j]=min(c[j],c[i]+d[i][j])     #循环更新最小响应时间
                        t|={j}
            que=t
        if len(c)==N:       #节点都遍历到了
            return max(c.values())      #返回节点最大时间
        else:
            return -1
```
