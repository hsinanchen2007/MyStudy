### 解题思路
递归过程中使用temp_path保存当前路径。
当遍历到叶子时，判断是否符合条件，符合就把temp_path加到path里

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        path=[]
        def get_sum(root,target,temp_path):
            if not root:
                return
            target-=root.val
            if not root.left and not root.right:
                if target==0:
                    temp_path.append(root.val)
                    path.append(temp_path)
                    return
                else:
                    return
            temp_path.append(root.val)
            get_sum(root.left,target,temp_path.copy())
            get_sum(root.right,target,temp_path.copy())
        get_sum(root,sum,[])
        return path
                

                

```