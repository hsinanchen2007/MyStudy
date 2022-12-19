### 解题思路
<中序遍历/先序遍历/后序遍历/层次遍历>
先序遍历：先自身，再左，后右。
#### 1.列表l保存结果
#### 2.辅助函数
intrav(root)递归调用自身完成先序遍历，在检测到节点为空时返回。将结果append至L中。
#### 3.函数中调用辅助函数
函数中调用辅助函数，返回L

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        L=[]
        def preTra(root):
            if not root:return
            L.append(root.val) 
            preTra(root.left)
            preTra(root.right)
        preTra(root)
        return L
```