```python
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        inDegree = [0] * len(graph)
        dp = [[]  for _ in range(len(graph))]
        for i, item in enumerate(graph):
            for num in item:
                inDegree[i] += 1
                dp[num].append(i)
        queue = [index for index in range(len(graph)) if inDegree[index] == 0]
        res = []
        while queue != []:
            top = queue.pop()
            res.append(top)
            for item in dp[top]:
                inDegree[item] -= 1
                if inDegree[item] == 0:
                    queue.append(item)
        return sorted(res)


```