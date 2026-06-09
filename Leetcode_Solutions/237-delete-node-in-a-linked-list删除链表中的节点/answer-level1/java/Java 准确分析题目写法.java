- **说明中表示链表至少包含两个节点。这里不做链表为null的判断。**
- **题目说明了是删除链表非末尾的节点，则node.next一定不为null。**
- **且参数只传了一个参，链表的结构没有向前走的指针，只有next指针，则是值的传递方式删除链表。**

```
public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
```
