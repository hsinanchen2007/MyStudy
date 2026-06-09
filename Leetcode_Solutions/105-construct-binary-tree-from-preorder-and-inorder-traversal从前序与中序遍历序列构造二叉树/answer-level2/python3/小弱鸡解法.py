### 解题思路
前序遍历的特点是，先出现的节点则必然在数中等于或高于后面的节点，而第一个节点必然是根节点，而中序的特点是，若确定
了根节点，则此节点位置左右两边及为左右子树，因此，将二者特性利用，使用前序遍历来寻找根节点，然后再用中序遍历的序列
进行两侧划分，依次递归可得到最终的树

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
        def build(preorder,inorder):
            if inorder==None or len(inorder)==0:
                return None
            ind = preorder[0]
            if ind in inorder:
                h = inorder.index(ind)
                node = TreeNode(ind)
                l = build(preorder[1:],inorder[:h])
                r = build(preorder[1:],inorder[h+1:])
                node.left=l
                node.right=r
                return node
            elif ind not in inorder:
                node = build(preorder[1:],inorder)
                return node
        node = build(preorder,inorder)
        return node

```