### 为何叫先中后序遍历

二叉树的先中后序遍历是根据根节点的位置来分的，先遍历根节点（根→左→右）就是先序，中间遍历根节点（左→根→右）就是中序，最后遍历根节点（左→右→根）就是后序。

### 三种遍历方式的递归实现
递归的思路还是很直观的，按照定义就能写出。下面贴一个很pythonic的递归实现：
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        ## 后序遍历（左→右→根）
        p = lambda x: p(x.left)+p(x.right)+[x.val] if x else []
        ## 中序遍历（左→根→右）
        p = lambda x: p(x.left)+[x.val]+p(x.right) if x else []
        ## 先序遍历（根→左→右）
        p = lambda x: [x.val]+p(x.left)+p(x.right) if x else []
        return p(root)
```
### 三种遍历方式的迭代实现
迭代的方法很多，这里贴一个我认为最好理解、最套路化的模板，是在[这篇题解](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/yan-se-biao-ji-fa-yi-chong-tong-yong-qie-jian-ming/)的基础上提炼优化的。
树的迭代遍历要借助栈。原理是也简单：
- 栈初始为`stack = [根]`,结果列表为初始空列表`rst = []`;
- 栈顶元素TreeNode根节点弹出，**根节点的属性**再按顺序入栈（这里的顺序很重要，是决定哪个序的关键）：`stack.extend([右节点,值,左节点])`。
- 然后再弹出栈顶元素。此时弹出的顺序就是`[左节点,值,右节点]`。

- 当弹出的元素是TreeNode节点而不是int值，将**此节点的属性**按上述入栈顺序继续入栈`stack.extend([右节点,值,左节点])`。
- 当弹出的元素是int值而不是TreeNode节点，将其放入结果列表` rst.append(值)`。
- 当弹出的是None，不做任何处理。
- 然后再弹出栈顶元素，当元素是TreeNode节点...当元素是int值...如此循环直到栈空，rst就是遍历结果。

上述过程自己手动模拟一遍就很清楚了，过程中**入栈顺序就是先/中/后遍历的反序**。代码如下：
```
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        stack,rst = [root],[]
        while stack:
            i = stack.pop()
            if isinstance(i,TreeNode):
                stack.extend([i.right,i.val,i.left]) ## 中序遍历
                # stack.extend([i.val,i.right,i.left]) ## 后序遍历
                # stack.extend([i.right,i.left,i.val]) ## 先序遍历
            elif isinstance(i,int):
                rst.append(i)
        return rst
```
是不是很好理解记忆呢！