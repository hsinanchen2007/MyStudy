```
    public void deleteNode(ListNode node) {
        // 脑筋急转弯，把后面的值都往前移就行了
        ListNode prev = node;
        while(node.next != null) {
            node.val = node.next.val;
            prev = node;
            node = node.next;
        }
        prev.next = null;
    }
```
