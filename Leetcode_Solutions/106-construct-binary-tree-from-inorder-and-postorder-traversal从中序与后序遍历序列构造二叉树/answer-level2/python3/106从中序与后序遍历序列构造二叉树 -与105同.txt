### 解题思路
与105从先序与中序遍历序列构造二叉树相同。
中序：[left,root,right]
后序：[left,right,root]
递归基：后序列表为空，已无根节点
根节点：postOrderList[-1]
找到根节点在中序中的索引index
左子树中节点个数：index
右子树中节点个数：end-index
左子树的中序/后序列表：inOrderList[:index],postOrderList[:index]
左子树的中序/后序列表: inOrderList[index+1:],postOrderList[index:-1]

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        #和<105build tree from preOrderList & inOrderList>相似
        #indoder:[left,root,right]  postorder:[left,right,root]
        if not postorder:return None
        root=TreeNode(postorder[-1])#根节点建立
        idxMap={val:ID for ID,val in enumerate(inorder)}
        index=idxMap[postorder[-1]]#根节点在中序遍历的位置
        root.left=self.buildTree(inorder[:index],postorder[:index])#建立左子树
        root.right=self.buildTree(inorder[index+1:],postorder[index:-1])#建立右子树
        return root


```