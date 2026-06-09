看了好多题解都不太明白，尤其是迭代的方法...所以翻了翻算法4，思路真的很清晰，也没有想象中那么复杂。
JAVA的代码可以直接看书，这里给个Python3的实现。看着代码比较多，其实很简单，后面有解释，一定要看完:-)

```python
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        # search node
        def find(root):
            if not root:
                return False
            if root.val == key:
                return True
            elif root.val < key:
                return find(root.right)
            elif root.val > key:
                return find(root.left)
        # find min Node
        def minNode(root):
            if root.left is None: return root
            return minNode(root.left)
        # delete min node
        def deleteMin(root):
            if root.left is None: return root.right
            root.left = deleteMin(root.left)
            return root
        # delete node
        def delete(root):
            if not root: return root
            if key < root.val:
                root.left = delete(root.left)
                return root
            elif key > root.val:
                root.right = delete(root.right)
                return root
            else:
                if root.right is None:
                    return root.left
                if root.left is None:
                    return root.right
                t = root
                root = minNode(t.right)
                root.right = deleteMin(t.right)
                root.left = t.left
                return root
        if not find(root):
            return root
        return delete(root)
```
这里是定义了几个函数，简单介绍下。
第一个函数`find`，是搜索BST中是否存在`key`，如果不存在就**直接返回原来的root**（注意不是返回`None`）。如果存在，则进行删除操作。

删除操作涉及三个函数，第一个`minNode`是用于找出树中**最小的节点**（注意返回的是节点，而不是值），第二个函数`deleteMin`是用于**删除一棵树中最小的节点**。

前两个函数都服务与最后一个函数`delete`，其用来真正执行删除操作。这个函数也是递归的，小于则在左枝执行删除操作，即通过`root.left = delete(root.left)`来**更新**左枝（这里注意，更新完之后下面要有`return root`来返回）；大于就通过`root.right = delete(root.right)`**更新**右枝并返回。如果是等于的话就略复杂一些。但是也就是三种情况。
1. 右枝为空，则用左枝替换，即前继节点替换（注意此处对于均为空的情况也是可以的）
2. 左枝为空，则用右枝替换，即后继节点替换（注意此处对于均为空的情况也是可以的）
3. 左右枝均存在，前驱后继均可，这里采用后继节点替换。调用`minNode`找到最小节点，之后在右枝用`deleteMin`将其删除，最后将其连接起来即可。

这里对最后的**左右枝均存在**的删除做进一步说明：
```python
t = root
root = minNode(t.right)
root.right = deleteMin(t.right)
root.left = t.left
return root
```
这里做的操作是，用`t`存储找到的`key`节点，之后将右枝最小节点绑定到`root`（完成位置的替换），之后右枝删除掉最小的节点，并将最小节点的右枝它。最后将待删除`key`节点的左枝`left`还原到`root`，至此完成全部的替换。