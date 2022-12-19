空间性能和时间性能都不太彳亍的方法，适合笔试的时候大脑一片空白时使用，建议A后看看其他题解的正常思路。。。

```python
class Solution:

    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        res = []
        def helper(node):
            if not node: return
            helper(node.left)
            res.append(node.val)
            helper(node.right)
        # 中序遍历
        helper(root)
        # 插值
        res.append(val)
        # 排序
        res.sort()
        # 重建二叉搜索树，每次取列表中间值为根节点
        # 左右各为左右子树，递归得到新的二叉搜索树
        def build(lst):
            if len(lst) == 0: return None
            if len(lst) == 1: return TreeNode(lst[0])
            node = TreeNode(lst[len(lst) // 2])
            node.left = build(lst[0:len(lst) // 2])
            node.right = build(lst[len(lst) // 2 + 1:])
            return node
        return build(res)

```