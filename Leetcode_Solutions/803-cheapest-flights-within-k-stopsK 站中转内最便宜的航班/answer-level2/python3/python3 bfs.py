### 解题思路
先处理数据，以出发点为key，中转站和价格为value构建字典，对处理好的数据进行bfs，开始超时，剪枝优化后通过

### 代码

```python3
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        from collections import defaultdict, deque
        flights_dict = defaultdict(list)

        visited = defaultdict(bool)
        for flight in flights:
            flights_dict[flight[0]].append((flight[1], flight[2]))

        queue = deque()
        queue.appendleft((src, 0, 0))
        min_price = float('inf')
        while queue:
            for _ in range(len(queue)):
                start, counter, cur_price = queue.pop()
                for end, price in flights_dict[start]:
                    # 到达目的地
                    if end == dst and counter <= K:
                        min_price = min(min_price, (cur_price + price))
                    elif counter <= K and (cur_price + price) < min_price:
                        queue.appendleft((end, counter + 1, cur_price + price))

        return min_price if min_price != float('inf') else -1

```