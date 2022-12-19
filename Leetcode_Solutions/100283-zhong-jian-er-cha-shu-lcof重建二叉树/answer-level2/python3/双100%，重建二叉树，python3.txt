### 解题思路
如果preorder和inorder都为空，直接返回
前序遍历preorder的第一个元素preorder[0]一定对应着该树的根节点
那么中序遍历inorder中preorder[0]之前的元素是根节点左子树对应的中序遍历，我们可以得知左子树的遍历之后的长度，设为L
那么根节点左子树对应的前序遍历是preorder[1:i+1]
同理可以得到根节点右子树的中序和前序遍历结果
分别用左子树和右子树的前序和中序遍历递归调用本函数

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
        def method(pre, mid):
            if not pre and not mid:
                return
            for i in range(len(mid)):
                if mid[i] == pre[0]:
                    left_mid = mid[:i]
                    left_pre = pre[1:i+1]
                    right_mid = mid[i+1:]
                    right_pre = pre[i+1:]
                    break
            res = TreeNode(pre[0])
            res.left = method(left_pre, left_mid)
            res.right = method(right_pre, right_mid)
            return res
        return method(preorder, inorder)

```