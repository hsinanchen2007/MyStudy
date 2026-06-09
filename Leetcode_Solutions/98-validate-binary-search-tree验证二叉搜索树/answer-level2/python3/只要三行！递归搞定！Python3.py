## 思路
+ 为了验证一棵树是否是BST，我们可以一个节点一个节点的查看。
+ 每一个节点都有一个最大值和最小值的范围。
+ 哎？为什么一个节点有一个最大值和最小值的范围？
+ 我们举个例子。
```
            5
    1               8
                3       10
```
+ 在上述的树当中，1比5小，8比5大，第一层OK
+ 再第二层，3比8小，10比8大，OK....OK吗？
+ 不OK！因为3在5的右子树，应当比5大。
+ 所以不可以直观地认为一个节点只要比父节点大或者小就可以了，它实际上是由大小范围的。
+ 对于这个3,它应该的范围就是(5,8)。
+ 最大值和最小值怎么更新呢？
+ 很简单，如果要检查的节点在这个节点的左边，那么最大值就是这个节点的值，最小值就是上一轮检查当中的最小值。
+ 反之亦然。

## 代码
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode, low = float('-inf'), high = float('inf')) -> bool:
        if not root:return True
        if not low<root.val<high:return False
        return self.isValidBST(root.left,low,root.val) and self.isValidBST(root.right,root.val,high)
```
+ 在代码中，有几个边界要强调一下
  + 当这个节点不存在的时候，就返回True。就代表父节点没有（左或右）孩子
  + 初始化root的时候，它没有最大最小的限制
  + 递归检查左右孩子，两个都为True才可以返回True

怎么样？是不是很简单~当然这个实际上修改了原来函数的参数，如果不修改的话，就新建一个函数，也是很简单的事~