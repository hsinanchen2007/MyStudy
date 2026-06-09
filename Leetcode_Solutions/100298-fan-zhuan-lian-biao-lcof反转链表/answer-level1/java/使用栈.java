```java
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null)
            return null;
        Stack<ListNode> stack = new Stack<>();
        for (; head != null; stack.push(head),head = head.next);
        ListNode node = head = stack.peek();
        for (; !stack.empty(); head.next = stack.pop(),head = head.next);
        head.next = null;
        return node;
    }
}
```