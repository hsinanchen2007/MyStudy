```java
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode l = head;
        // 头节点后移一位
        head = l.next;
        while (l != null && l.next != null) {
            
            ListNode after = l.next;
            // 最后两个节点
            if (after.next == null) {
                after.next = l;
                l.next = null;
                break;
            }
            // 最后三个节点 
            else if (after.next.next == null) {
                l.next = after.next;
                after.next = l;
                break;
            }
            // 不少于四个节点 
            else {
                ListNode nn = after.next;
                l.next = nn.next;
                after.next = l;
                l = nn;
            }
        }
        return head;
    }
}
```
