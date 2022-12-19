### 解题思路

层次遍历，链表生成。

### 代码

```python []
class Solution:
    def listOfDepth(self, tree: TreeNode) -> List[ListNode]:
        head, trees = ListNode(0), tree and [tree]
        while trees:
            tmp = head
            for tree in trees:
                tmp.next = ListNode(tree.val)
                tmp = tmp.next
            yield head.next
            trees = [leave for tree in trees for leave in (tree.left, tree.right) if leave]
```