这题的核心思想其实就是把node的下一位的值覆盖给node，然后跳过node的下一位
因为我们无法访问到head节点，所以除了直接从node开始往下找，其他都是不现实的
即
a->b->c->d->e->f 变为 a->b->d->d->e->f 然后把第一个d的next设为e，跳过第二个d
代码为：
```
class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next

```
