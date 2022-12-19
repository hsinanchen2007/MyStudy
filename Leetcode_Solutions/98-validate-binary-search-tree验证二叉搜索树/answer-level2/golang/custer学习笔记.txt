# 思考

1. 二叉搜索树特性，中序遍历输出的数组是否为升序的-技巧只要后面的值大于前面节点就可以
1. 递归判断，递归函数设计需要技巧-对于递归找左子树的最大值要小于根节点，右子树的最小值大于根节点

# Python实现

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        inorder = self.inorder(root)
        # 判断是否是递增的
        return inorder == list(sorted(set(inorder)))
    
    # 中序遍历，左根右
    def inorder(self, root):
        if root is None:
            return []
        return self.inorder(root.left) + [root.val] + self.inorder(root.right)
```

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        self.prev = None
        return self.helper(root)
    
    def helper(self, root):
        if root is None:
            return True
        # 中序遍历，左子树
        if not self.helper(root.left):
            return False
        # 判断根节点大小关系是否满足
        if self.prev and self.prev.val >= root.val:
            return False
        # 根节点变为前继结点递归调用下去
        self.prev = root
        # 中序遍历，右子树
        return self.helper(root.right)
```

```java
public boolean isValid(TreeNode root, Integer min, Integer max) {
	if (root == null) return true;
    if (min != nill && root.val <= min) return false;
    if (max != nill && root.val >= max) return false;
    
    return isValid(root.left, min, root.val) && isValid(root.right, root.val, max);
}

public boolean isValidBST(TreeNode root) {
    if (root == null) {
        return true;
    }
    boolean left = isValidBST(root.left);
    boolean mid = pre >= root.val ? false : true;
    pre = root.val;
    boolean right = isValidBST(root.right);
    return left && mid && right;
}
```

# Go实现

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isValidBST(root *TreeNode) bool {
    if root == nil {
    	return true
    }
    return isBST(root, math.MinInt64, math.MaxInt64)
}
func isBST(root *TreeNode, left, right int) bool {
    if root == nil {
        return true
    }
    if left >= root.Val || right <= root.Val {
    	return false
    }
    return isBST(root.Left, left, root.Val) && isBST(root.Right, root.Val, right)
}
```


