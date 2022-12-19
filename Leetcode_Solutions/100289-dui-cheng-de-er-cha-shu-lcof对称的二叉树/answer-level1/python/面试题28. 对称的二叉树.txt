### 解题思路
其实就是前序遍历，我们对当前的root需要做什么？
> 判断当前的root是否符合镜像的要求，如果两个root的值不相同，那么肯定不符合镜像，如果两个root的同时到了最下面的None,那肯定返回True, 如果一个树较高，那么肯定也是不对称的，其他的情况只需要按照框架进行递归就可以了！！
![image.png](https://pic.leetcode-cn.com/2c29a50b54a37b5ef485dffb06c577d98af87c03c1310e039e1907e250561096-image.png)

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
        def help(root1, root2):
            if root1 is None and root2 is None:
                return True
            if root1 is None or root2 is None:
                return False
            if root1.val != root2.val:
                return False
            return help(root1.left, root2.right) and help(root1.right, root2.left)
        
        if root is None:
            return True
        else:
            return help(root.left, root.right)
            
```