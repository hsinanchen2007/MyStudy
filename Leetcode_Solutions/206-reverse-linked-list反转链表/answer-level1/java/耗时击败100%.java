### 代码
```java
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null) return head;
        ListNode left = head, right = head.next;
        head.next = null;
        while (right != null) {
            left = right;
            right = right.next;
            left.next = head;
            head = left;
        }
        return head;
    }
}
```

```java
class Solution {
    ListNode rear = null;
    
    public ListNode reverseList(ListNode head) {
        if (head != null) backtrack(head).next = null;
        return rear;
    }
    
    public ListNode backtrack(ListNode head) {
        if (head.next == null) rear = head;
        else backtrack(head.next).next = head;
        return head;
    }
}
```