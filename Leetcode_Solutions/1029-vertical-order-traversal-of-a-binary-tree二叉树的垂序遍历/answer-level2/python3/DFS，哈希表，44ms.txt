DFS获取每个元素的深度和列值，保存在哈希表，列作为key，值和深度作为value。排序按深度和值的大小排序，最后按列值顺序输出。
```
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        hashMap = {}
        def dfs(node, idx, depth):
            if not node:
                return
            if idx not in hashMap:
                hashMap[idx] = {node.val: depth}
            else:
                hashMap[idx][node.val] = depth
            dfs(node.left, idx - 1, depth + 1)
            dfs(node.right, idx + 1, depth + 1)
        dfs(root, 0, 0)
        for i in hashMap:
            hashMap[i] = sorted(hashMap[i], key=lambda x: [hashMap[i][x], x])
        keys = sorted(hashMap.keys())
        return [hashMap[i] for i in keys]
```
