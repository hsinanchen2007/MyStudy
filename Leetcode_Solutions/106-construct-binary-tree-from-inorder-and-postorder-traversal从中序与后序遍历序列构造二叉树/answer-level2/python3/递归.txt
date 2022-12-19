### 解题思路
预备知识点：
中序遍历：左-中-右
后序遍历：左-右-中
可以看出，这里的前序和中序都是相对于根节点（就是上面的“中”）来说的。
根节点什么时候被遍历，则称为什么序遍历。
因此后前序遍历为：中-左-右

对于这题：
中序遍历 inorder  = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
我们如何构造树？
我们先找到根节点，在后序遍历中，根节点最后一个被遍历，因此根节点为3
在中序遍历中，根节点在第二个被遍历，我们可以使用根节点把它分成三块：[9],[3],[15,20,7]。在中序遍历中，根节点前面的是左子树的部分，右边的是右子树的部分，因此我们由此将后序遍历也拆分成左右子树和根：[9],[15,7,20],[3]。
因此我们得到了下图：

![image.png](https://pic.leetcode-cn.com/e68b2128044e2a05f7a672bf1b3092b71a9b84dc541d68b53055f6fa6be1c924-image.png)

接下去，我们要将左右子树构造出来
同理，对于每颗子树再走一遍流程就可以了。因此我们使用递归。
接下去将这个过程用代码表示出来就可以了

（TIP:如何在后序遍历中切分左右子树，即如何将[9,15,7,20]切分成[9],[15,7,20]？
我们注意到，在前序和中序遍历中，左子树都是第一个被遍历的，因此我们用根节点切分中序得到[9],[3],[15,20,7]后,发现左子树有1个节点，因此直接把[9,20,15,7]第一个切分出来就可以了。
）



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
        if not preorder:
            return None
        if len(preorder)==1:
            #长度为1直接返回
            head=TreeNode(preorder[0])
            return head
        #拿到根节点
        head=TreeNode(preorder[0])
        #找到根节点在中序中的位置
        head_position_in_inorder=inorder.index(preorder[0])

        #切分中序
        left_inorder=inorder[:head_position_in_inorder]
        right_inorder=inorder[head_position_in_inorder+1:]

        #切分后序
        left_preorder=preorder[1:head_position_in_inorder+1]
        right_preorder=preorder[head_position_in_inorder+1:]

        #递归
        head.left=self.buildTree(left_preorder,left_inorder)
        head.right=self.buildTree(right_preorder,right_inorder)
        return head
```
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
        if not postorder:
            return None
        if len(postorder)==1:
            #长度为1直接返回
            head=TreeNode(postorder[0])
            return head
        #拿到根节点
        head=TreeNode(postorder[-1])
        #找到根节点在中序中的位置
        head_position_in_inorder=inorder.index(postorder[-1])

        #切分中序
        left_inorder=inorder[:head_position_in_inorder]
        right_inorder=inorder[head_position_in_inorder+1:]
        
        #切分后序
        left_postorder=postorder[:head_position_in_inorder]
        right_postorder=postorder[head_position_in_inorder:-1]

        #递归
        head.left=self.buildTree(left_inorder,left_postorder)
        head.right=self.buildTree(right_inorder,right_postorder)
        return head
```