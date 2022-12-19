### 解题思路
执行用时 :28 ms, 在所有 Python3 提交中击败了93.97%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了5.78%的用户

这个比前序和中序难一些，注意比较

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        stk = []
        while root or stk:
            # 一直走到叶子节点
            while root:
                stk.append(root)
                if root.left:
                    root = root.left
                else:
                    root = root.right
                    
            top = stk.pop()
            res.append(top.val)
            
            if stk and stk[-1].left == top:
                # 如果有右节点 其对应的根节点还没有出栈 
                # 这样就是先打印右节点再打印根节点
                root = stk[-1].right  
            else:
                # 左右节点都出栈了
                # 作为叶子节点出栈打印
                root = None
                
        return res
```