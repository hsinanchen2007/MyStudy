直接删除即可
```
    public void deleteNode(ListNode node) {
        if(node == null || node.next == null) return;
        
        node.val = node.next.val;
        node.next = node.next.next;
    }
```
