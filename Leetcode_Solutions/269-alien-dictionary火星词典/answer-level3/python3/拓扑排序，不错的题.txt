先每两个比较，找出单词的排序序列，然后装入字典，最后拓扑排序。
```
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        dic={}
        if len(words)==0:return ""
        for i in range(1,len(words)):
            for j in range(min(len(words[i]),len(words[i-1]))):
                if words[i][j] == words[i-1][j]:
                    continue
                if words[i][j] != words[i-1][j]:
                    if not dic.get(words[i-1][j]):dic[words[i-1][j]]=words[i][j]
                    else: 
                        if words[i][j] not in dic[words[i-1][j]]:
                            dic[words[i-1][j]]+=words[i][j]
                    break
            if len(words[i-1])>len(words[i]) and words[i-1][:len(words[i])]==words[i][:len(words[i])]:return ""
        #如果dic中没有元素，即words中所有值是相同的,或者后面的大于前面的但前面的都一样
        if not dic :return words[-1]
        for i in range(len(words)):
            for k in words[i]:
                if dic.get(k) ==None:dic[k]=""
        print(dic)
        #拓扑排序
        def topoSort(graph):     
            in_degrees = dict((u,0) for u in graph)   #初始化所有顶点入度为0     
            num = len(in_degrees)     
            for u in graph:         
                for v in graph[u]:             
                    in_degrees[v] += 1    #计算每个顶点的入度     
            Q = [u for u in in_degrees if in_degrees[u] == 0]   # 筛选入度为0的顶点     
            Seq = []     
            while Q:         
                u = Q.pop()       #默认从最后一个删除         
                Seq.append(u)         
                for v in graph[u]:             
                    in_degrees[v] -= 1    #移除其所有出边
                    if in_degrees[v] == 0:        
                        Q.append(v)          #再次筛选入度为0的顶点
            if len(Seq) == num:       #输出的顶点数是否与图中的顶点数相等
                return Seq     
            else:         
                return None
        topo=topoSort(dic)
        if not topo:return ""
        res=""
        for x in topo:
            res+=x
        return res
```
