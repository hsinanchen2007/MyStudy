### 解题思路
同 剑指offer 习题 [面试题27. 二叉树的镜像](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/)
这里主要是要考虑到 比较 left.left 和 right.right  以及 left.right 和 right.left


刚开始一直想着用前序遍历的方法来做，发现根本不对，前序遍历无法唯一确定一棵树。
[中序遍历也不对](https://leetcode-cn.com/problems/symmetric-tree/solution/dui-cheng-er-cha-shu-by-leetcode/121770)

二叉树前序遍历居然不唯一

看例子 [1,2,2,2,null,2, null] 如果补上所有的叶子节点的 null, 会导致出错。

中序遍历根本不对，无法解决此问题。




### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def helper(left, right):
            if left == None and right == None:
                return True
            elif left == None or right == None:
                return False
            else:
                if left.val != right.val:
                    return False
                else:
                    return helper(left.left, right.right) and helper(left.right, right.left)
        
        if root == None:
            return True
        return helper(root.left, root.right)
```

#### 前序遍历的错误代码
``` python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def preorder(root):
            if root == None:  # 这个语句在递归时不起作用
                return [None]
            else:
                if root.left and root.right:
                    return preorder(root.left) + [root.val] + preorder(root.right)
                elif not root.left and not root.right:
                    return [root.val] 
                    # 这里如果返回 [None, root.val, None] 会导致样例 [1,2,2,2,null,2,null] 出错
                elif root.left:
                    return preorder(root.left) + [root.val, None]
                else:
                    return [None, root.val] + preorder(root.right)
        # 对实例 [5,4,1,null,1,null,4,2,null,2,null] 继续错误
        A = preorder(root)
        if A == A[::-1]:
            return True
        else:
            return False
```