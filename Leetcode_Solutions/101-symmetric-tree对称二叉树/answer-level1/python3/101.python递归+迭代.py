### 解题思路
根据官方解题的思路，自己又写了一遍。

主要是选取一个镜像树，这里设原树为tree,镜像树为new_tree
满足条件： tree.left.val == new_tree.right.val and tree.right.val == new_tree.left.val

迭代的思路：每次从队列中取两个相邻节点，如果是对称的，这两个节点的值会相等，如果不是对称的，这两个节点的值不会相等。然后将该两个节点的子节点以上述的条件添加到队列中。循环遍历，知道队列为空或中途不对称返回False。



### 代码

```python

from collections import deque

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """



        # 递归算法
        
        # 空树也是对称的
        if not root:
            return True
        def new_trees(root_left,root_right):
            if root_left == None and root_right == None:
                return True
            if root_left == None or root_right ==None:
                return False  
            if root_left.val !=root_right.val:
                return False
            return all((new_trees(root_left.left,root_right.right),new_trees(root_left.right,root_right.left)))
        return new_trees(root.left,root.right)
        



        # 迭代算法
        if not root:
            return True
        deq = deque([root.left,root.right])
        while deq:
            root_right = deq.pop()
            root_left = deq.pop()
            if root_left == None and root_right == None:
                continue
            if root_left == None or root_right == None:
                return False
            if root_left.val != root_right.val:
                return False
            deq.extend([root_left.left,root_right.right,root_left.right,root_right.left])
        return True

```