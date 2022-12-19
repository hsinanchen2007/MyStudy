### 解题思路
找到根结点以后分别对前序数组和中序数组切片，生成新的前序中序数组。都在注释里了

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
        if not preorder or not inorder:
            return None
        if len(preorder)!=len(inorder):
            return None
        root= preorder[0]                   #找根节点
        rootNode=TreeNode(root)             #创建一个以root为根节点的树
        pos=inorder.index(root)             #找到根节点在中序数组位置的索引

        in_left=inorder[:pos]               #中序数组左子树
        in_right=inorder[pos+1:]            #中序数组右子树
        pre_left=preorder[1:pos+1]          #前序数组左子树 
        pre_right=preorder[pos+1:]          #前序数组右子树

        leftNode=self.buildTree(pre_left,in_left)     #递归左子树
        rightNode=self.buildTree(pre_right,in_right)  #递归右子树

        rootNode.left=leftNode              #递归出来的结果补全到根节点下面
        rootNode.right=rightNode
        return rootNode

```