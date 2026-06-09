个人觉得官方题解python代码，在寻找到最右边的树叶后，操作复杂难懂，不如我写的简洁。
class Solution(object):
    def preorderTraversal(self, root):
        """
        :param root: TreeNode
        :return: List[int]
        """

        node, output = root, []
        while node:
            if not node.left:
                output.append(node.val)
                node = node.right
            else:
                predecessor = node.left
                while predecessor.right:
                    predecessor = predecessor.right
                predecessor.right = node.right
                output.append(node.val)
                node = node.left
        return output