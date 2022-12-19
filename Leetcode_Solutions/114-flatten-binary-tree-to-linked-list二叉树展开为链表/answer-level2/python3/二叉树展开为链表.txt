### 递归

* 算法：
    * 如果根节点空
        * 返回
    * 如果左子树空
        * 对右边进行flatten
        * 返回
    * 如果右子树空
        * 对左边进行flatten
        * 左边链表移动到右边
        * 返回
    * 左右子树都不为空
        * 左右两边都进行flatten
        * 左边链表结尾指向右边链表开始
        * 左边链表移动到右边
        * 返回

* 只要明白，对于当前节点`root`，我对左右两边flatten后，`root.left`和`root.right`就都形成了链表，这样的话，下面的处理步骤非常简单，只需要把两者连接起来即可，然后移到`root.right`。
* 在这四种情况中，写法上后两种可以合并成一种，因为只要左子树不为空就不干扰我们的处理，所以代码中体现了三种情况。
* 注意，当将根节点的右指针指向左链表后，左指针要指向null，否则会有duplicates。

```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root is None:
            return
        if root.left is None:
            self.flatten(root.right)
            return

        self.flatten(root.left)
        self.flatten(root.right)

        tmp = root.left
        while(tmp.right):
            tmp = tmp.right
        tmp.right = root.right
        root.right = root.left
        root.left = None
```
