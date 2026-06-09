### 解题思路
/**
 * 加一个头结点解决问题（前面的题目遇到过）
 * 不修改原先链表的情况下，都可尝试往这方面想
 * 最后一步注意加一个null进行收尾
*/

### 代码

```java
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        ListNode head1 = dummy;
        while(head!=null){
            if(head.val!=val){
                head1.next = head;
                head1 = head1.next;
            }
            head = head.next;
        }
        head1.next=null;
        return dummy.next;
    }
}
```