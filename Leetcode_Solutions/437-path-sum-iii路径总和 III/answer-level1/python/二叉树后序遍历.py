### 解题思路
通过后序遍历，从下往上分别计算每个节点与其子树的组合
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
        
class Solution:
    def pathSum(self, root: TreeNode, sum_param: int) -> int:
        # 二叉树后序遍历
        def traversal_suc(node):
            # 结果集中为sum_param的路径个数
            nonlocal count
            sum_ = []
            if node:
                # 通过递归获得左右子树结果集left、right
                left = traversal_suc(node.left)
                right = traversal_suc(node.right)
                sum_ += left
                sum_ += right
                # 根据左右子节点的结果集left、right来确定node的结果集
                for i in range(len(sum_)):
                    # node结果集为[val+node.val for val in left+right]
                    sum_[i] += node.val
                    count += sum_[i]==sum_param
                # 加入以node为最深节点的路径
                count += node.val==sum_param
                sum_.append(node.val)
                return sum_
            else:
                # 空节点不影响父节点结果集，返回[]
                return []
        count = 0
        traversal_suc(root)
        return count