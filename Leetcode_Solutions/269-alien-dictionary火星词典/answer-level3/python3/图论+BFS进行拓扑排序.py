1. 处理火星字典，找到每个字母之前的前置字母
2. 根据前置字母图，用BFS进行拓扑排序
```
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        graph = {}    #邻接链表，对每个key，value为必须在key之前的字母
        all_words = [] #存储所有出现的字母
        stack = [words] 
        sample = []
        # 将火星字典转成图，用邻接链表表示
        while stack:  
            L = stack.pop()
            Second = []
            F = []
            for i in range(len(L)):
                if L[i][0] not in all_words:
                    all_words.append(L[i][0])
                if not F:
                    F.append(L[i][0])
                    if len(L[i]) >= 2:
                        Second.append(L[i][1:])
                elif L[i][0] == F[-1]:
                    if len(L[i]) >= 2:
                        Second.append(L[i][1:])
                else:
                    F.append(L[i][0])
                    if Second:
                        stack.append(Second)
                    Second = []
                    if len(L[i]) >= 2:
                        Second.append(L[i][1:])
            if Second:
                stack.append(Second)
            sample.append(F)
        while sample:
            S = sample.pop()
            n = len(S)
            for i in range(n):
                for j in range(i):
                    if S[i] in graph:
                        if S[j] not in graph[S[i]]:
                            graph[S[i]].append(S[j])
                    else:
                        graph[S[i]] = [S[j]]
        #利用广度优先搜素对图进行拓扑排序 
        ans = ""
        isAdded = set()
        newAdded = set()
        itertime = 0
        stop = 0
        while stop == 0 and itertime <= len(all_words) + 1:
            itertime += 1
            stop = 1
            for i in all_words:
                if i not in isAdded:
                    stop = 0
                flag = 0
                if i in graph:                  
                    for j in graph[i]:
                        if j not in isAdded:
                            flag = 1
                if flag == 0 and i not in isAdded:
                    newAdded.add(i)
                    ans = ans + i
            for w in newAdded:
                isAdded.add(w)
            newAdded = set()
        return ans if itertime <= len(all_words) + 1 else ""
```
