 思路：将所有花园分为指定确定颜色和没确定颜色的，每次选邻接节点最多的节点分配颜色，选中点的颜色不能和与它邻接的、已经指定颜色的点的颜色冲突
```
class Solution:
    def gardenNoAdj(self, N: int, paths ) :
        linkdict={i:[] for i in range(1,N+1)} #linkdict的key对应花园号，value存对应的邻接花园号
        colored={} #存已经确定颜色的花园号和它对应的颜色
        for i in paths :
            linkdict[i[0]].append(i[1])
            linkdict[i[1]].append(i[0])
        for i in sorted(linkdict.keys() , key=lambda x : len(linkdict[x]) , reverse=True) : #选邻接点最多的花园
            choice=[1,2,3,4] #候选颜色
            for j in linkdict[i] :
                if j in colored and colored[j] in choice :
                    choice.remove(colored[j])
            colored[i]=choice[0] #剩余候选颜色中第一个作为指定的颜色
        ans=[None for _ in range(N)]
        for i,j in colored.items() :
            ans[i-1]=j
        return ans
```

