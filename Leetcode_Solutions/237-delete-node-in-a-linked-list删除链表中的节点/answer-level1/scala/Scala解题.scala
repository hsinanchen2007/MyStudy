```
def deleteNode(node: ListNode ) {
    node.x = node.next.x;
    node.next = node.next.next;
}
```
