注意下头结点的删除就好

```java
  public void deleteNode(ListNode node, int n) {
    if (node==null){
      return;
    }
    if (node.val == n){
        if(node.next == null){
            node = null;
            return;
        }
        node.val = node.next.val;
        node.next = node.next.next;
        return;
    }
    while (node.next != null){
      if (node.next.val == n){
        node.next = node.next.next;
        return;
      }
      node = node.next;
    }
  }
```

