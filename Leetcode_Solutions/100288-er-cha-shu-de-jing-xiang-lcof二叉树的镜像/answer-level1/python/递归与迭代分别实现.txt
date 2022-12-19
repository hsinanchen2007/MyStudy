```
class Solution(object):
    # 递归，宏观思考，
    def mirrorTree1(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root == None:  # 如果root为空则返回-1表示不用反转
            return -1
        if root.left == None and root.right == None:  # 递归基，到叶子了不用交换，直接返回这个节点
            return root
        else:
            if root.left == None:  # 当前节点左孩子空，右孩子不空，那就镜像以右孩子为根节点的子树
                self.mirrorTree(root.right)
            elif root.right == None:  # 当前节点右孩子空，左孩子不空，镜像以左孩子为根节点的子树
                self.mirrorTree(root.left)
            else:  # 当前节点左孩子右孩子都不空，那就左右子树都做镜像
                self.mirrorTree(root.right)
                self.mirrorTree(root.left)
            root.left, root.right = root.right, root.left  # 对于上面三种情况都需要把当前节点的左右做一下镜像
        return root  # 返回当前节点
    # 迭代
    def mirrorTree2(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        # 迭代
        if root == None:  # 如果root为空则返回-1表示不用反转
            return -1
        q = []  # 广度优先，找个容器做队列
        q.append(root)  # 先把根节点放进队列
        while q != []:  # 只要队列不空，就做底下的操作
            tem = q.pop(0)  # 出队元素
            if tem.left != None:  # 如果出队节点的左孩子不空，就把左孩子入队
                q.append(tem.left)
            if tem.right != None:  # 如果出队节点的右孩子不空，就把右孩子入队
                q.append(tem.right)
            tem.left, tem.right = tem.right, tem.left   # 不管左右空与不空，都需要做镜像操作，这样可以保证每个节点都做了镜像操作。
        return root  # 返回根节点
```