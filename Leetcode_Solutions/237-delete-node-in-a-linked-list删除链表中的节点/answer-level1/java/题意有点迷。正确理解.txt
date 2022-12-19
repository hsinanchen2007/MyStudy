一般链表函数都是传头节点，但是这题没有给你头节点，而是直接给了你要删除的那个节点。
给定函数里面的node的含义就是要删除的那个节点。理解了就好办了。
```
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
```
