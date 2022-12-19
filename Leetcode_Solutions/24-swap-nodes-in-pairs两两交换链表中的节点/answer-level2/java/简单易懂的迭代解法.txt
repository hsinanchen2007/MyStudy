简单易懂的迭代解法
- a, b, c, d依次指向连续四个节点. 
每次循环：
- STEP1. 做节点交换； 
- STEP2. 右移两个节点；

```java
  public ListNode swapPairs(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }
    ListNode a = head;
    ListNode b = head.next;
    ListNode c = b.next;
    ListNode d = c == null ? null : c.next;
    head = head.next;
    while (c != null && d != null) {
      // swap
      b.next = a;
      a.next = d;
      // shift right 2 nodes
      a = c;
      b = d;
      c = b.next;
      d = c == null ? null : c.next;
    }
    b.next = a;
    a.next = c; // warn：a, b dead loop
    return head;
  }
```