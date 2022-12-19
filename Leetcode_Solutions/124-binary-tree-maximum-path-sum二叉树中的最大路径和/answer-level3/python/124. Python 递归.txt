### 解题思路
首先肯定是要对树进行遍历的，这里应该选择后序遍历，因为只有计算子树的最大路径和才能得到当前树的最大路径和。
对于某棵子树，它可能包含最终路径，但也有可能只是最终路径的一部分，也或者不包括最终路径。所以这里要分开考虑。
这里设置了一个局部变量`max_num`记录的是当前子树包括的最大路径和，而递归的返回值是作为最大路径的一部分。
然后进行递归即可。
*注意：由于树中的答案可能存在负数，所以在比较过程中有些位置需要和-inf进行比较，有些地方需要和0进行比较。*

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        max_num = float('-inf')
        def get_res(root):
            nonlocal max_num
            if root is None:
                return float('-inf')
            left_max = get_res(root.left)
            right_max = get_res(root.right)
            temp = root.val + max(left_max, 0) + max(right_max, 0) # 当前子树最大路径和
            if temp > max_num:
                max_num = temp
            return max(root.val + max(left_max, right_max, 0), float('-inf')) # 作为最大路径的一部分
        temp = get_res(root)
        print(temp, max_num)
        return max(temp, max_num)
```