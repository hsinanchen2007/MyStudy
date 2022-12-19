```
class Solution(object):
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """ 
        dummy_head = TreeNode(float("inf"))
        dummy_head.left = root
        parent, node = None, dummy_head
        while node:
            if node.val == key:
                if not node.left or not node.right:
                    if parent.left == node:
                        parent.left = node.left or node.right
                    else:
                        parent.right = node.left or node.right
                else:
                    right_node = node.right
                    right_parent = None
                    while right_node.left:
                        right_parent, right_node = right_node, right_node.left

                    if right_parent:
                        right_parent.left = right_node.right

                    right_node.left = node.left
                    right_node.right = node.right if right_parent else node.right.right
                    if parent.left == node:
                        parent.left = right_node
                    else:
                        parent.right = right_node

            if key < node.val:
                parent, node = node, node.left
            else:
                parent, node = node, node.right

        return dummy_head.left
```
