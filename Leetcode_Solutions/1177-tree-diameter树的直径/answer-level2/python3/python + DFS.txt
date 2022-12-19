### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:

        # Time complexity : O(N)
        node_num = len(edges) + 1
        adj = collections.defaultdict(list)
        res = 0
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)

        def get_longest_path(index, visited):
            nonlocal res
            max_path1, max_path2 = 0, 0
            visited[index] = True
            for child in adj[index]:
                if not visited[child]:
                    max_path = get_longest_path(child, visited)
                    if max_path > max_path1:
                        max_path2 = max_path1
                        max_path1 = max_path
                    elif max_path > max_path2:
                        max_path2 = max_path
            visited[index] = False
            res = max(res, max_path1 + max_path2)
            return max(max_path1, max_path2) + 1
        visited = [False] * node_num
        get_longest_path(0, visited)
        return res
```