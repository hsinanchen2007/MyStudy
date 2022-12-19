这道题就是，就是删除节点时的问题，步骤如下：

1. 获取要删除节点 cur 的前一个节点pre
2. pre.next = cur.next

但是这里有一个坑，就是删除头节点的问题，如下：

[1, 1]  val = 1

我们在删除1的时候，如果直接就让要删除的节点（1）去前驱节点指向其后继节点，非常容易就会造成空指针问题。要解决这个问题，也非常简单，使用哨兵节点即可（哨兵节点广泛应用于树和链表中，如伪头、伪尾、标记等，它们是纯功能的，通常不保存任何数据，其主要目的是使链表标准化，如使链表永不为空、永不无头、简化插入和删除。）。步骤如下：

1. 创建哨兵节点sentinel
2. 将哨兵节点作为头节点（sentinel = head）
3. 继续删除节点时的步骤
4. 返回sentinel.next
```
public ListNode removeElements(ListNode head, int val) {
    if (head == null) {
        return null;
    }

    // 创建哨兵节点并作为头节点
    ListNode sentinel = new ListNode(0);
    sentinel.next = head;

    ListNode cur = head;
    ListNode pre = sentinel;

    // 删除
    while (cur != null) {
        if (cur.val == val) {
            pre.next = cur.next;
        } else {
          pre = cur;
        }
        cur = cur.next;
    }

    // 返回本来的头节点
    return sentinel.next;
}
```
