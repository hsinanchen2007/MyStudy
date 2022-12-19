### 解题思路
先右子树再根再左子树遍历
递归时需要注意：
1、终止条件
2、这一轮递归需要做什么操作
3、需要给调用者返回什么

对于这道题：
1、终止条件为空节点或叶子
2、遍历每一个节点时，需要
- 将调用者给的加数给右子树，并拿到右子树的返回值
- 把返回值加到节点上
- 把节点值传给左子树，并拿到左子树的返回值

3、将左子树的返回值返回



### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        def adder(root,add_num):
            if not root:
                return add_num
            if not root.left and not root.right:
                root.val+=add_num
                return root.val
            right=adder(root.right,add_num)
            root.val+=right
            left=adder(root.left,root.val)
            return left
        adder(root,0)
        return root

        
```