```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    #使用BFS来确定p节点是否在根为root的树内
    def isAncestor(self, root, p):
        if root == None:
            return False
        q = []
        q.append(root)
        while len(q) > 0:
            cur_node = q.pop()
            if cur_node == p:
                return True
            if not cur_node.left == None:
                q.append(cur_node.left)
            if not cur_node.right == None:
                q.append(cur_node.right)
        return False

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        #pre_order先序遍历，祖先节点都在前面，然后在先序遍历序列里查找p和q的下标，他们共同的祖先节点肯定在0-最小下标的范围内，从最小下标到0逆序查找是否在子树里
        #stack作为栈使用，完成对二叉树进行先序遍历
        stack = []
        #pre_order保存先序遍历的序列
        pre_order = []
        #由于每个节点的值是唯一的，所以使用val_list保存节点值的先序序列，以便于快速查找p和q节点的下标
        val_list = []
        #下面是求先序遍历的代码
        stack.append(root)
        while len(stack)>0:
            node = stack.pop(len(stack)-1)
            pre_order.append(node)
            val_list.append(node.val)
            if not node.right == None:
                stack.append(node.right)
            if not node.left == None:
                stack.append(node.left)
        
        #求取p和q节点在先序遍历序列里的下标
        p_ind = val_list.index(p.val)
        q_ind = val_list.index(q.val)
        #求最小下标，及最小下标表示的节点，也就是可能的最近公共祖先
        ind = min(p_ind, q_ind)
        #cur_node表示可能的最近公共祖先节点
        cur_node = pre_order[ind]

        #t_node表示要查找的节点
        t_node = p
        if cur_node == p:
            t_node = q
        
        #逆序查找最近的公共祖先，公共祖先一定在先序遍历0-最小下标的范围内
        for i in range(ind, -1, -1):
            cur_node = pre_order[i]
            #isAncestor用来确定是否t_node节点在以cur_node节点为祖先的子树内
            if self.isAncestor(cur_node, t_node):
                return cur_node
```
