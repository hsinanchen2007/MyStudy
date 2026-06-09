### 解题思路
dfs，在递归过程中记录每个节点所代表的子树的最大节点值，最小节点值，以及节点值的和，是否满足搜索树。搜索数的判断在每个节点的逻辑为，判断左子树最大值是否小于当前节点(或者左子树不存在)，右子树的最小值是否大于当前节点(或者右子树不存在)，若满足则该子树为二叉搜索树。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        self.res = 0
        
        def dfs(cur):
            if not cur:
                return [True,0,0,0]
            left = dfs(cur.left)
            right = dfs(cur.right)
            if left[0] and right[0] and (not cur.left or cur.val>left[1]) and (not cur.right or cur.val < right[2]):
                if cur.right:
                    tmp_max = right[1]
                else:
                    tmp_max = cur.val
                if cur.left:
                    tmp_min = left[2]
                else:
                    tmp_min = cur.val
                tmp_sum = left[3]+right[3]+cur.val
                self.res = max(self.res,tmp_sum)
                return [True,tmp_max,tmp_min,tmp_sum]
            
            
            #[是否是搜索树，最大值，最小值，所有节点的和]
            return [False,0,0,0]
        dfs(root)
        return self.res
            
            
            
            
```