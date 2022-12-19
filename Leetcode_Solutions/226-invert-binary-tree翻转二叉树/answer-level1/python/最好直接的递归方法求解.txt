### 解题思路
上来对于二叉树想到的就是递归方法进行处理。
进一步分析可知：1.对于非最后一排的节点，每个节点都是一个小树，要与对称位置的小树进行“再处理”，也就是重复调用函数。
               2.最后一排的节点，要与对称位置直接交换节点。这里就是我们递归的终点。
对最后一排进行分析，可以参与交换的两边节点四种可能的状态：
                    空空，非空空，空非空。
                    空空：两个节点无需处理，直接返回
                    剩下的两种情况，需要考虑到非空一侧多出不止一排的情况，因此需要对该非空节点，看作一个子树，先把它左右分支调用函数处理                       了，再把该节点整个和对面节点交换。

                    至于非空非空情况，说明递归并未到最后一排，继续调用函数处理这对节点的下一排的四个分支，然后将两个节点值交换。

![Capture.JPG](https://pic.leetcode-cn.com/1e54a836e0f00e9d090dbc4227a062cff710aac6f7c09b468a4ecbf8a70f815a-Capture.JPG)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if(root == None):
            return(None)
        
        def exchangeTree(root_1:TreeNode, root_2:TreeNode):
            if(root_1==None)and(root_2==None):
                return(root_1,root_2)
            elif((root_1==None)and(root_2!=None)):
                root_2.left, root_2.right = exchangeTree(root_2.left, root_2.right)
                return(root_2,root_1)
            elif((root_1!=None)and(root_2==None)):
                root_1.left, root_1.right = exchangeTree(root_1.left, root_1.right)
                return(root_2,root_1)               
            elif((root_1!=None)and(root_2!=None)):
                root_1.left, root_2.right = exchangeTree(root_1.left, root_2.right)
                root_1.right, root_2.left = exchangeTree(root_1.right, root_2.left)
                root_1.val, root_2.val = root_2.val, root_1.val
                return(root_1,root_2)
        
        root.left, root.right = exchangeTree(root.left,root.right)
        return(root)
```