# python 递归中序遍历
```python []
queen = []
def midileTraval(root):
    if root.left == root.right == None:
        queen.append(root.val)
        return
    if root.left:
        midileTraval(root.left)
    queen.append(root.val)
    if root.right:
        midileTraval(root.right)

        
def fun(root):
    midileTraval(root)
    print(queen)

    for i in range(1, queen.__len__()):
        if (queen[i] - queen[i-1]) < 0:
            return False 
    return True

class Solution(object):
    """
    0.中序遍历
    """
            
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        if root.left == root.right == None:
            return True
        return fun(root)
    
```

