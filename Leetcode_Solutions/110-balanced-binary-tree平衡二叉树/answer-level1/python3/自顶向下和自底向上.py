## 思路:

这道题是[求树的高度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/dfshe-bfs-by-powcai)的延伸版, 我们只要求左右子树相差的高度是否超过 1，就可以了!

首先，要**自顶向下方法**，如下代码:

```python [-Python]
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        return abs(self.height(root.right)-self.height(root.left))<2 and self.isBalanced(root.left) and self.isBalanced(root.right)
	# 求高度
    def height(self, node):
        if not node:
            return 0
        return 1+max(self.height(node.right),self.height(node.left))
```

上面的方法要不断递归左右子树, 有重复部分,所以时间复杂度为$O(n^2)$

下面用**自底向上**，直接看代码就能理解了!

时间复杂度为$O(n)$

## 代码:

```python [1]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        self.res = True
        def helper(root):
            if not root:
                return 0
            left = helper(root.left) + 1
            right = helper(root.right) + 1
            #print(right, left)
            if abs(right - left) > 1: 
                self.res = False
            return max(left, right)
        helper(root)
        return self.res
```



```java [1]
public class BalancedBinaryTree {
    boolean res = true;

    public boolean isBalanced(TreeNode root) {

        helper(root);
        return res;

    }

    private int helper(TreeNode root) {
        if (root == null) return 0;
        int left = helper(root.left) + 1;
        int right = helper(root.right) + 1;
        if (Math.abs(right - left) > 1) res = false;
        return Math.max(left, right);
    }
}
```

