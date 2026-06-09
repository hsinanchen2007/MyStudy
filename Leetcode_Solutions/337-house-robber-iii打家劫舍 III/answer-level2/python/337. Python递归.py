### 解题思路
感觉动态规划题用迭代做多了再用递归就有点不那么顺手了。
对树型结构的操作基本上都要用递归来实现，这道题也不例外，对于每个节点可以分成打劫或者不打劫：
（1）rob: root.val + 隔了一个节点的子树的所有子树的最大值的和
（2）not_rob: 左右两棵子树的最大值的和
该子树最后的最大值是上面两种情况的最大值。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        mem_dict = {}
        def get_res(root):
            if root is None:
                return 0
            if root in mem_dict:
                return mem_dict[root]
            # 该房子打劫
            rob_left_num = get_res(root.left.left) + get_res(root.left.right) if root.left else 0
            rob_right_num = get_res(root.right.left) + get_res(root.right.right) if root.right else 0
            rob_num = root.val + rob_left_num + rob_right_num
            # 该房子不打劫
            not_rob_left_num = get_res(root.left) if root.left else 0
            not_rob_right_num = get_res(root.right) if root.right else 0
            not_rob_num = not_rob_left_num + not_rob_right_num
            # 求最大方案
            max_num = max(rob_num, not_rob_num)
            mem_dict[root] = max_num
            return max_num
        return get_res(root)

            
```