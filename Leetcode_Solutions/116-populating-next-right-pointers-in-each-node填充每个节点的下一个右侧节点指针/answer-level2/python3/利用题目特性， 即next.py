层次遍历， 利用上一层的节点的next值可以不用记录它们
ps， 解法大概是可以使用于非完美二叉树， 但是我没试， 理论分析可以...

```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        cur = root
        next_level_rightest = Node(0)   # 使用一个新的节点的目的是防止root.left不存在
        next_level_cur = next_level_rightest
        while cur:
            if cur.left:
                next_level_cur.next = cur.left
                next_level_cur = next_level_cur.next
            if cur.right:
                next_level_cur.next = cur.right
                next_level_cur = next_level_cur.next
            cur = cur.next
        if next_level_rightest.next:
            self.connect(next_level_rightest.next)
        return root
```