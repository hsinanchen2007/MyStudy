
参考：
[二叉树的前序遍历_题解](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/)


### 1.递归

和前序遍历类似，先写好print的模板框架，然后再在上面进行更新修改：
```
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        self.inOrder(root, res)
        
        return res
    
    def inOrder(self, root, res):
        if not root:
            return res
        
        self.inOrder(root.left, res)
        res.append(root.val)
        self.inOrder(root.right, res)
        
        return res
```


![image.png](https://pic.leetcode-cn.com/51782a457e38c1a4357794a516a73a4091735e1dbd733bd40fe166d81c0b5903-image.png)


### 2.迭代

占坑，睡了，醒了起来写