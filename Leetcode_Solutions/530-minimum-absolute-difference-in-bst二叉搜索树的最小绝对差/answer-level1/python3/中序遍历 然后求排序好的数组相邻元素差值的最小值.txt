### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        #先中序遍历
        def inorder(root):
            if root is None:
                return None
            inorder(root.left)
            res.append(root.val)
            inorder(root.right)
            return res
        res=[]
        res=inorder(root)
        #对于排序好的数组怎么求差值
        #[1,3,6,7,9]
        #[ ,1,3,6,7,9]
        min_value=float('inf')
        for i in range(len(res)-1):
            temp=res[i+1]-res[i]
            if temp<min_value:
                min_value=temp
        return min_value


```