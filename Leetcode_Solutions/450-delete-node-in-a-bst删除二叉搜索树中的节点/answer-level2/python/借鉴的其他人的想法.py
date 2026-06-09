### 解题思路
基本上照抄别人的思路：
    个人理解这个问题的技巧在于查找节点的parent的保存和右子树的最小值的parent保存
    1.首先添加辅助Node到根节点，这样我们无需判断删除节点在根的这种特殊情况；
    2.查找，并记录父节点
    3.删除操作：
        1. 当删除节点为叶节点时，删除该节点与父节点的连接；
        2. 当删除节点只有左子树时，将父节点与该左子树连接；
        3. 当删除节点存在右子树时，将右子树最小值替换到删除节点，并对右子树进行修复。
            右子树修复：
                当右子树的最小值为删除节点的right时，将删除节点的right连接到最小值的right;
                其他情况，将最小值的parent的left连接到最小值的right

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return root
        firstNode = TreeNode(float("-inf"))
        firstNode.right = root
        temproot = firstNode
        while temproot and key != temproot.val:
            parent = temproot                      # 查找时记录查找元素的parent
            if key < temproot.val:
                temproot = temproot.left
            else:
                temproot = temproot.right
        if not temproot:      # 没有找到时
            return root
        if not temproot.left and not temproot.right:      #当查找到的节点没有子节点时，将其父节点的链接删除
            if temproot is parent.right:
                parent.right = None
            else:
                parent.left = None
        elif not temproot.right:                          #当查找到的节点只有左节点，将其父节点连接到其左节点
            if temproot is parent.right:
                parent.right = temproot.left
            else:
                parent.left = temproot.left
        else:                                             #当查找到的节点存在右节点时，将右节点的最小值放到更新为查找到的位置
            tempnode = temproot.right
            while tempnode and tempnode.left:
                pptemparent = tempnode
                tempnode = tempnode.left
            temproot.val = tempnode.val 
            if tempnode is temproot.right:                #修复右子树
                temproot.right = tempnode.right
            else:
                pptemparent.left = tempnode.right
        return firstNode.right              
            
```