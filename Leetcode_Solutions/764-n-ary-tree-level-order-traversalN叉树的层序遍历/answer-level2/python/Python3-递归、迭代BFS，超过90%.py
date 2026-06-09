# 429. N叉树的层序遍历 - 递归BFS
```
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        res = []
        def helper(root, depth):
            if not root: return
            if len(res)==depth:
                res.append([])
            res[depth].append(root.val)
            for node in root.children:
                helper(node, depth+1)
        helper(root, 0)
        return res
```
# 429. N叉树的层序遍历 - 迭代BFS
```
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root: return
        cur_level = [root]
        res = []
        while cur_level:
            tmp = []
            next_level = []
            for node in cur_level:
                tmp.append(node.val)
                for next_node in node.children:
                    next_level.append(next_node)
            res.append(tmp)
            cur_level = next_level
        return res
```