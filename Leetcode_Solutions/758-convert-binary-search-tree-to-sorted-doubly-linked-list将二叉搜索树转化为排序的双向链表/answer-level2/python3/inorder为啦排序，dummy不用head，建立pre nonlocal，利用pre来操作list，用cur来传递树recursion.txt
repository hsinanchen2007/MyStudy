### 解题思路
https://www.youtube.com/watch?v=YZ7Lm8AKwPs
重点：
inorder为啦排序，
dummy不用head，
建立pre nonlocal，
利用pre来操作list，用cur来传递树recursion



用dummy 的方法可以不用head
dummy的方法看起来有点怪一开始，但是只要记住，dummy.right是第一个点，
dummy.left.right是第一个点的右边用来连接最后一个点，跳出递归pre也实际走到最后了
就会操作了
主要记住pre是用来操作linkedlist，注意每次要移动pre到cur
cur是当前树的节点


```
def treeToDoublyList(self, root: 'Node') -> 'Node': 
    if root is None:
        return None

    dummy = Node(0,None,None)
    pre = dummy

    def _helper(cur):
        if cur is None:
            return None
        nonlocal pre
        _helper(cur.left)
        pre.right = cur
        cur.left = pre
        pre = cur
        _helper(cur.right)

    _helper(root)  
    pre.right = dummy.right
    dummy.right.left = pre
    return dummy.right
```

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node': 
        if root is None:
            return None

        dummy = Node(0,None,None)
        pre = dummy

        def _helper(cur):
            if cur is None:
                return None
            nonlocal pre
            _helper(cur.left)
            pre.right = cur
            cur.left = pre
            pre = cur
            _helper(cur.right)

        _helper(root)    
        pre.right = dummy.right
        dummy.right.left = pre
        return dummy.right

```