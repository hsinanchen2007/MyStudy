### 解题思路
1. 在二叉树的三种非递归遍历中，后序遍历复杂一点。在这种遍历中，每个根节点都要经过三次：第一次遇到它时要立即转去处理其左子树，第二次从左子树经由它转去处理右子树，第三次从右子树回来才应该处理根节点数据，然后返回上一层。
2. 执行node = root，方便遍历以免引起混淆。node的值是当前节点（可能为空），在实现遍历的循环中维持一种不变的关系：
     **·** 栈中节点序列的左边是二叉树已经遍历过的部分，右边是尚未遍历的部分；
     **·** 如果node不为空，其父节点就是栈顶节点；
     **·** node为空时栈顶就是应该访问的节点。
根据被访问节点是其父节点的的左节点或右节点就可决定下一步该怎么做：若是左节点就转到右节点；若是右节点就应该处理根节点并强制退栈。
3. 函数定义中外层循环内嵌套了一个内层循环，该内层循环的目标是找到下一个应访问的节点。

**注意：** 
1.内层循环找到当前子树的最下最左节点，将其入栈后终止；
2.若被访问节点是其父节点的左子节点，应直接转到其右兄弟节点继续访问；
3.若被处理节点是其父节点的右子节点，设node = None将迫使外层循环的下次迭代弹出并访问更上一层的节点。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []   # 用来存储后序遍历节点的值
        stack = []  
        node = root
        while stack or node:
            while node:
                stack.append(node)  # 第一次入栈的是根节点
                #判断当前节点的左子树是否存在，若存在则持续左下行，若不存在就转向右子树
                node = node.left if node.left is not None else node.right
            #循环结束说明走到了叶子节点，没有左右子树了，该叶子节点即为当前栈顶元素，应该访问了
            node = stack.pop() # 取出栈顶元素进行访问
            res.append(node.val) # 将栈顶元素也即当前节点的值添加进res
            # （下面的stack[-1]是执行完上面那句取出栈顶元素后的栈顶元素）
            if stack and stack[-1].left == node: #若栈不为空且当前节点是栈顶元素的左节点
                node = stack[-1].right   ## 则转向遍历右节点
            else:
                node = None  # 没有左子树或右子树，强迫退栈
        return res
```