```
输入：单向链表a->b->c->d->e->f中的节点c
结果：不返回任何数据，但该链表变为a->b->d->e->f
```
要把删除节点c，即node即为给定要删除的节点。要删除节点node，以上面为例，要删除节点c，我们可以把节点c的val变为节点d(node.next)的val，此时可以看成节点c已经变成了节点d，改变c(node)的下一个节点为e(node.next.next)。

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```
