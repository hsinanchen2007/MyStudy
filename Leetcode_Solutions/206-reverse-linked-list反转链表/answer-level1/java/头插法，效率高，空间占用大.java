```java
class Solution {
    public ListNode reverseList(ListNode head) {
        // 利用头插法实现
        ListNode myHead = new ListNode(0);
        while (head != null) {
            ListNode node = new ListNode(0);
            node.val = head.val;
            node.next = myHead.next;
            myHead.next = node;
            head = head.next;
        }
        return myHead.next;
    }
}
```