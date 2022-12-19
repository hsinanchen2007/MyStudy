当前节点最大值 = max(左侧子数最大值+当前节点值，右侧子树最大值+当前节点值，当前节点值）
若左右侧都大于0，则闭环最大路径为左侧开环最大+右侧开环最大+当前节点值

```
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        global max_sum
        max_sum = float("-inf")
        def get_max(root):
            global max_sum
            if root == None:
                return 0
            else:
                tmp_left = get_max(root.left)
                tmp_right = get_max(root.right)
                if tmp_left>=0 and tmp_right>=0:
                    tmp_max = tmp_left + tmp_right + root.val
                else:
                    tmp_max = max(tmp_left+root.val,tmp_right+root.val,root.val)
                if tmp_max > max_sum:
                    max_sum = tmp_max
                return max(tmp_left+root.val,tmp_right+root.val,root.val)

        get_max(root)
        return max_sum

```
