### 思路

**两重DFS**

```
第一重：找到起点。先判断当前节点，如果不对就判断左子树和右子树。
第二重：从找到的起点开始判断剩下的点。
```

##### Python3代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        if head == None:
            return True
        if root == None:
            return False
        # judge root, then judge root.left and root.right
        return self.isSub(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
    
    def isSub(self, head, node):
        # list is over
        if head == None:
            return True
        # list is not over and tree is over
        if node == None:
            return False
        # not equal
        if not head.val == node.val:
            return False
        # equal, then left and right
        return self.isSub(head.next, node.left) or self.isSub(head.next, node.right)
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1367-Linked-List-in-Binary-Tree/1367.py)

### 参考

[Jerry学长题解](https://leetcode-cn.com/problems/linked-list-in-binary-tree/solution/zhe-ti-jiu-shi-subtreeyi-mao-yi-yang-by-jerry_nju/)