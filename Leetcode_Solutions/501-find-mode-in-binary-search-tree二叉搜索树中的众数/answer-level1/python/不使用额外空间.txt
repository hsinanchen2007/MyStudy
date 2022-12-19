```
class Solution(object):
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.result = []
        self.count = 0

        def dfs(node, last_node, last_count):
            if not node:
                return last_node, last_count

            last_node, last_count = dfs(node.left, last_node, last_count)

            if last_node and last_node.val == node.val:
                last_count = last_count + 1
            else:
                last_count = 1

            if last_count == self.count:
                self.result.append(node.val)
            elif last_count > self.count:
                self.count = last_count
                self.result = [node.val]

            return dfs(node.right, node, last_count)

        dfs(root, None, 0)
        return self.result
```

题目的要求很清楚了，用递归得出结果。但是类似本题的问题，明显遍历更方便。如果用递归，至少应该是个中级题吧。