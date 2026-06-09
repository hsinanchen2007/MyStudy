这里的重点在于对集合的运用
    初始化answer都为0 
    首先获得节点的邻接点
    然后遍历所有节点
        遍历所有节点的邻接点
            用flowers集合减去邻接点当前的花种类
            （这里的话，如果花是0则flowers集合不变）
        利用pop获取flowers剩下花类的第一种花并赋给当前节点
    返回answer



``` python
class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        #构建一个answer数组
        answer = [0]*N
        #初始化nei字典元素为空列表
        nei = [[] for _ in range(N)]
        # 构建无向邻接表，无邻居则不构建
        for path in paths:
            nei[path[0]-1].append(path[1])
            nei[path[1]-1].append(path[0])
        for node in range(1,N+1):    #遍历所有节点
            flowers={1,2,3,4}
            #临时存储邻居含有的花类型
            a = set()
            for sinode in nei[node-1]: #遍历邻居
                a.add(answer[sinode-1])
            flowers = flowers - a 
            answer[node-1] = flowers.pop()
                               
        return answer
```
