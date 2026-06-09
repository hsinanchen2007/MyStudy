### 解题思路
递归遍历。

### 代码

```python3
class Solution:
    def treeToDoublyListCore(self, root: 'Node') -> ('Node', 'Node'):
        """
        :param root: 树的根节点
        :return: 双向链表的 头节点 和 尾节点
        """
        # 根为空，那么 对应的双向链表的 头节点 和 尾节点 也为空
        if root is None:
            return None, None

        # 左子树 对应的 双向链表的头节点和尾节点
        left_head, left_tail = self.treeToDoublyListCore(root.left)
        # 右子树 对应的 双向链表的头节点和尾节点
        right_head, right_tail = self.treeToDoublyListCore(root.right)

        # 根的 左节点 与 左子树的尾节点 互相连接
        # 根的 右节点 与 右子树的头节点 互相连接
        root.left, root.right = left_tail, right_head
        if left_tail:
            left_tail.right = root
        if right_head:
            right_head.left = root

        # 左子树的头节点 如果存在则作为当前 双向链表的头节点，否则使用 根节点。尾节点同理。
        return left_head if left_head else root, right_tail if right_tail else root

    def treeToDoublyList(self, root: 'Node') -> 'Node' or None:
        """
        递归遍历
        时间复杂度：O(N)，所有节点遍历一次。
        空间复杂度：O(N)，当二叉搜索树退化为链表时，树的深度为 N.
        """
        head, tail = self.treeToDoublyListCore(root)
        # 改造成循环双向链表
        if head and tail:
            head.left, tail.right = tail, head
        return head
```