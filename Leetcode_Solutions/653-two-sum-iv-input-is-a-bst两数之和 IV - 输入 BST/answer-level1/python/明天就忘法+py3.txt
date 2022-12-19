### 解题思路
此处撰写解题思路
先中序遍历 然后 双指针
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        nums=[]
        # 中序
        def helper(root):
            if not root:
                return 
            helper(root.left)
            nums.append(root.val)
            helper(root.right)
        helper(root)
     
        n=len(nums)
        l=0
        r=n-1
        while l<r:
            target=nums[l]+nums[r]
            if target==k:
                return True
            elif target>k:
                r-=1
            else:
                l+=1
        return False

```