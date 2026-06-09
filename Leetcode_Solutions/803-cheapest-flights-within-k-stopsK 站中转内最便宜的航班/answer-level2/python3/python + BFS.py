```python
class Solution:
	def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
		# K => bfs
		if flights == [] or src == dst : return 0 # special case
		queue = collections.deque([(src, 0)])
		cost = [float('inf')] * n
		cost[src] = 0
		adjList = collections.defaultdict(list)
		costList = collections.defaultdict(tuple)
		for x, y, c in flights:
			adjList[x].append(y)
			costList[(x, y)] = c
			
		for _ in range(K + 1):
			length = len(queue)
			for i in range(length):
				top, c = queue.popleft()
				for nei in adjList[top]:
					if costList[(top, nei)] + c < cost[nei]:
						cost[nei] = costList[(top, nei)] + c
						queue.append((nei, cost[nei]))
		return cost[dst] if cost[dst] != float('inf') else -1
```