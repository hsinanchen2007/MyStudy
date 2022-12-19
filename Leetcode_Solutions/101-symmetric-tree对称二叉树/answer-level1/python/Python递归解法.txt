### 解题思路
边看题解，边思考，对递归不熟悉就需要多练习，就算不是很懂，也要坚持写题解，把自己思考的过程写出来，我相信慢慢的，慢慢的就能体会递归的精髓了。
**如何判断是否是对称的？**
1、首先当前输入的两个子节点的值不为空，而且相等；

2、当前两个子节点的左子树和右子树要相等，当前两个子节点的节点的右子树和左子树必须相等

3、当1、和2、同时满足时，才能说明是对称的

4、然后递归调用
5、其实还是没想明白。。。。我要哭了

### 代码

```

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        
        def Duichen(root1,root2):
            if not root1 and not root2:  ##当前根节点如果为空，那么就是对称的
                return True
            if not root1 or not root2:
                return False
            return root1.val==root2.val and Duichen(root1.left,root2.right) and Duichen(root1.right,root2.left)
            
        return Duichen(root,root)

```