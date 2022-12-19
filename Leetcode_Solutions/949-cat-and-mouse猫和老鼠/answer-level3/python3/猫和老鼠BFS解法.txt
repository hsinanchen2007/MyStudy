1. 总体思路是由已知状态倒推。
2. 用（mouse,cat,turn）记录老鼠和猫的位置以及该回合轮到谁行动，turn=1老鼠行动，turn=2猫行动。
3. 用color记录胜利状态：color[mouse][cat][turn]=1老鼠胜利，color[mouse][cat][turn]=2猫胜利。
4. 下面讲一下实现过程：
- 初始化：color[0][i][turn]=1, color[i][i][turn]=2
- 遍历所有的已知状态：
- 1.找到能到该状态的所有上一步状态并遍历（findprevstatus）
- 2.**如果已知状态是猫（鼠）胜利，且上一步状态是猫（鼠）行动，则上一步状态也是猫（鼠）胜利，并加入已知状态；如果上一步状态是鼠（猫）行动，则遍历上一步状态所能到达的所有状态，如果全是猫（鼠）胜利，则上一步状态是猫（鼠）胜利，并加入已知状态。**（本题的核心要点，需要仔细琢磨，想清楚了这道题就迎刃而解了。）
- 3.所有已知状态全部标记完毕，如果color[1][2][1]已经被标记则返回标记状态，反之返回0。
```
class Solution:
    def catMouseGame(self, graph: List[List[int]]) -> int:
        def findprevstatus(graph,curstatus):
            ret=[]
            mouse,cat,turn=curstatus
            if turn==1:#则上一轮premouse=mouse,precat,preturn=2,找出能到cat的点，就是graph[cat]中的点。
                for precat in graph[cat]:
                    if precat==0:
                        continue
                    ret.append((mouse,precat,2))
            else:
                for premouse in graph[mouse]:#则上一轮premouse,precat=cat,preturn=1,找出能到mouse的点，就是graph[mouse]中的点。
                    ret.append((premouse,cat,1))
            return ret
        leng=len(graph)#BFS方式,t=1老鼠先行动，t=2猫先行动
        color=[[[0]*3 for _ in range(leng)] for _ in range(leng)]
        q=[]
        for i in range(1,leng):
            for t in range(1,3):
                color[0][i][t]=1#老鼠胜利
                q.append((0,i,t))
                color[i][i][t]=2#猫胜利
                q.append((i,i,t))
        while q:
            curstatus=q.pop(0)
            mouse,cat,turn=curstatus
            for prestatus in findprevstatus(graph,curstatus):
                premouse,precat,preturn=prestatus
                if color[premouse][precat][preturn]!=0:
                    continue
                if color[mouse][cat][turn]==preturn:
                    color[premouse][precat][preturn]=preturn
                    q.append(prestatus)
                else:#默认color[cat][mouse][turn]==turn
                    if turn == 2:#color[cat][mouse][2]=2如果color[cat][premouse][1]=1 全部color[cat][nextpremouse][2]=2
                        flag=True
                        for nextpremouse in graph[premouse]:
                            if color[nextpremouse][precat][turn]!=turn:
                                flag=False
                                break
                        if flag:
                            color[premouse][precat][preturn]=turn
                            q.append(prestatus)
                    else:
                        flag=True
                        for nextprecat in graph[precat]:
                            if nextprecat==0:
                                continue
                            if color[premouse][nextprecat][turn]!=turn:
                                flag=False
                                break
                        if flag:
                            color[premouse][precat][preturn]=turn
                            q.append(prestatus)
        return color[1][2][1]
```
