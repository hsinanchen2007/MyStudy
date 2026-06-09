### 解题思路
# input: 前序遍历, 中序遍历
# ouput: 根节点，左树的 前序遍历 和 中序遍历， 右树的 前序遍历 和 中序遍历
==》 将根节点与左右子树根节点连接，递归左右子树

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        # preorder: 根节点，        左子树前序，    右子树前序
        # inorder： 左子树中序，    根节点，        右子树中序

        # input: 前序遍历, 中序遍历
        # ouput: 根节点，左树的 前序 和 中序， 右树的前序和中序
        # 递归
        def helper(pre_head, pre_tail, in_head, in_tail):
            if pre_head <= pre_tail:
                # 前序首元素 一定是 root节点
                root = TreeNode(preorder[pre_head])
                
                # 根据root节点，可将中序遍历 拆成左右子树的 中序
                root_idx_inorder = inorder.index(preorder[pre_head])
                in_head_left = in_head # 左树中序起点不变
                in_tail_left = root_idx_inorder-1  # root左侧
                in_head_right = root_idx_inorder+1 # root右侧
                in_tail_right = in_tail # 右树中序终点不变
                
                # 根据中序的左右子树长度，可推出前序左右子树
                pre_head_left = pre_head+1 # root右侧
                pre_tail_left = pre_head+1 + (root_idx_inorder-in_head-1) # 加上左树长度
                pre_head_right = pre_tail_left + 1 # 左树结尾右侧
                pre_tail_right = pre_tail # 不变

                # 连接节点，并递归
                root.left = helper(pre_head_left, pre_tail_left, in_head_left, in_tail_left) # 返回左子树根节点
                root.right = helper(pre_head_right, pre_tail_right, in_head_right, in_tail_right) # 返回左子树根节点
                
                # 返回根节点
                return root

        return helper(0, len(preorder)-1, 0, len(inorder)-1)

```
已知【后序遍历】和【中序遍历】 构造二叉树 同理。

