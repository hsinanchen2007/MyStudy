```python
class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        # BFS
        queue = initialBoxes
        res = 0
        visited = set()
        while True:
            tempQueue = []
            copy = queue[:]
            while queue != []:
                top = queue.pop(0)
                if status[top] == 1:    
                    if top not in visited:
                        res += candies[top]
                        visited.add(top)
                    for k in keys[top]:
                        status[k] = 1
                else:
                    tempQueue.append(top)
                for box in containedBoxes[top]:
                    tempQueue.append(box)
            queue = tempQueue
            if queue == [] or queue == copy: break
        return res
```
