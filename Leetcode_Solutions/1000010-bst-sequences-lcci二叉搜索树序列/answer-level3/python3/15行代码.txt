**搜索**
- 使用一个queue存储下个所有可能的节点
- 然后选择其中一个作为path的下一个元素
- 递归直到queue元素为空
- 将对应的path加入结果中
- 由于二叉搜索树没有重复元素, 而且每次递归的使用元素的顺序都不一样, 所以自动做到了去重
```python
class Solution:
    def BSTSequences(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return [[]]
        res = []
        def findPath(cur, q, path):
            if cur.left:
                q.append(cur.left)
            if cur.right:
                q.append(cur.right)
            if not q:
                res.append(path)
                return
            for i, nex in enumerate(q):
                newq = q[:i] + q[i + 1:]
                findPath(nex, newq, path + [nex.val])
        findPath(root, [], [root.val])
        return res
```
