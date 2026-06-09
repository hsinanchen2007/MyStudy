### 解题思路
通过中序遍历BST，生成一个升序数组；这样`next`方法`pop`头元素，`hasNext`方法通过判断升序数组是否为空即可；

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:
    """
    通过中序遍历方法遍历BST，按升序方式保存节点；
    """

    def __init__(self, root: TreeNode):
        """
        利用栈结构进行遍历
        """
        node_stack = []
        self.num_list = []
        cur = root
        while cur or node_stack:
            while cur:
                node_stack.append(cur)
                cur = cur.left
            cur = node_stack.pop()
            self.num_list.append(cur.val)
            cur = cur.right
                    

    def next(self) -> int:
        """
        @return the next smallest number
        """
        return self.num_list.pop(0)
        

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        if self.num_list:
            return True
        else:
            return False
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```