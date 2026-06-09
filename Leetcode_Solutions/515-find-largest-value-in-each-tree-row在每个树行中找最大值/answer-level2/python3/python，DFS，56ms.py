思路：DFS，用字典保存每层最大值。key为深度，value为当前最大值。最后遍历字典value返回就行了。简单易懂。
```
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        hashMap = {}
        def dfs(node, depth):
            if not node:
                return
            else:
                if depth not in hashMap:
                    hashMap[depth] = node.val
                else:
                    hashMap[depth] = max(node.val, hashMap[depth])
            dfs(node.left, depth + 1)
            dfs(node.right, depth + 1)
        dfs(root, 1)
        return [hashMap[i] for i in hashMap]
```
