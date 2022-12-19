### 解题思路
重点是获取两棵树的叶子节点。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:

        def getLeaves(root):  # 获取叶子节点
            leaves = []       # 存放叶子节点的值
            nodeList = []      # 存放右子树的根节点
            while root is not None or nodeList:   # root是递归变量
                while root is not None:   
                    nodeList.append(root.right)   # 如果根节点不为空，则把右孩子节点放入
                    if root.left is None and root.right is None:  # 当前根节点没有孩子时，即当前根节点是叶子节点，把它的值存到leaves中
                        leaves.append(root.val)   
                    root = root.left # 否则继续对根节点的左孩子做这个操作
                root = nodeList.pop() # 开始对根节点的右孩子做上述相同操作
            return leaves
     
        leaves1 = getLeaves(root1)
        leaves2 = getLeaves(root2)
     
        # 手动实现两个列表的是否一致的对比
        if len(leaves1) != len(leaves2):  # 如果长度就不一致，肯定不相同
            return False
        else:
            for i in range(len(leaves1)):  # 相同位置的值是相同的，一直比对，直到列表最后一个元素
                if leaves1[i] == leaves2[i]:
                    continue
                else:
                    return False
            return True


        
```