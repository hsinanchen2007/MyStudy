题目保证了一定存在答案，也就是说肯定存在种花的方式使得相互连接的花园种植不同种类的花，因此可以按照序号从小到大来为花园选择种植的花的种类，只要保证选择的花的种类不与跟它相连且序号比它小的花园的花相同就行了。  
```Python
class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        ans = [0] * N
        graph = [set() for _ in range(N)]
        for path in paths:
            x = path[0] - 1
            y = path[1] - 1
            graph[x].add(y)
            graph[y].add(x)
        for i in range(N):
            candidates = set([1,2,3,4])
            for child in graph[i]:
                if child < i:
                    candidates.discard(ans[child])
            ans[i] = list(candidates)[0]
        return ans
```