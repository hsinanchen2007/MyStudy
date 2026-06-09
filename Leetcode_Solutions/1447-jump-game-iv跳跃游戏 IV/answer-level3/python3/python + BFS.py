```python
class Solution:
    def minJumps(self, arr: List[int]) -> int:
        # arr.length <= 5 * 1e4
        dis = [float('inf')] * len(arr)
        dis[0] = 0
        hash_table = collections.defaultdict(list)
        for i, num in enumerate(arr):
            hash_table[num].append(i)

        # bfs
        # Time complexity : O(N)
        # Space complexity: O(N)
        queue = collections.deque([0])
        while queue:
            top = queue.popleft()
            for nei in hash_table[arr[top]]:
                if dis[top] + 1 < dis[nei]:
                    dis[nei] = dis[top] + 1
                    queue.append(nei)
            hash_table[arr[top]] = []

            if top > 0 and dis[top - 1] > dis[top] + 1:
                dis[top - 1] = dis[top] + 1
                queue.append(top - 1)

            if top < len(arr) - 1 and dis[top + 1] > dis[top] + 1:
                dis[top + 1] = dis[top] + 1
                queue.append(top + 1)

        return dis[-1]
```