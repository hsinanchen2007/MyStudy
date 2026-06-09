//因为我们拿不到单向链表的上一个Node对象
//只能另想办法，
//可以把下一个节点的值替换成当前结点，让当前结点的下一个结点指向当前节点的下下结点
```
 public void deleteNode(ListNode node) {
        //是单向链表没办法拿到上一个结点
        node.val = node.next.val;
        node.next = node.next.next;   
    }
```
