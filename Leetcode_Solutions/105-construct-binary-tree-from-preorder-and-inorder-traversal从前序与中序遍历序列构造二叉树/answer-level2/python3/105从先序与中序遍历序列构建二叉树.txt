### 解题思路
#### 0.preOrder & inOrder
由先序遍历的性质可得先序列表：[root,left,right]
由中序遍历的性质可得中序列表：[left,root,right]
#### 递归建树
递归的建立树：
#### 1）递归基
递归基：先序列表为空：已无根节点
#### 2）根节点/左子树/右子树的建立
根节点：preOrderList[0]
找到根节点在中序列表的索引index
左子树的节点个数：index
右子树的节点个数：end-index
左子树的先序列表：preOrderList[1:index+1]
左子树的中序列表：inOrderList[:index]
右子树的先序列表：preOrderList[index+1,:]
右子树的中序列表: inOrderList[index:]

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
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder: return None#递归基：无先序列表（无根节点）
        root=TreeNode(preorder[0])#先序遍历中的首元素是根节点
        idxMap={val:ID for ID,val in enumerate(inorder)}#在中序遍历中，值：索引
        index=idxMap[preorder[0]]#找到根节点在中序列表中的位置，
        #在中序列表中index左侧为左子树的节点，右侧为右子树的节点；
        #在先序列表中[1,index]为左子树的节点，[index+1,end]为右子树的节点
        root.left=self.buildTree(preorder[1:index+1],inorder[:index])#建立左子树
        root.right=self.buildTree(preorder[index+1:],inorder[index+1:])#建立右子树
        return root
        


```