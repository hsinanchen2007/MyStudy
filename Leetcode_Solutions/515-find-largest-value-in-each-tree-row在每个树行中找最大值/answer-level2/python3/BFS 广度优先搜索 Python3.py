- 使用BFS
- 建立一个数组来保存结果（树的level对应数组的index）

```
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        result = []

        q = [(root, 0)]

        while q:
            curr, level = q.pop(0)

            if level == len(result):
                result.append(curr.val)
            result[level] = max(result[level], curr.val)

            if curr.left:
                q.append((curr.left, level + 1))
            if curr.right:
                q.append((curr.right, level + 1))
            
        return result
```

