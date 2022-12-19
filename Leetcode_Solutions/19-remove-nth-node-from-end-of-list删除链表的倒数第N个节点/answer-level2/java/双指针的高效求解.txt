### 解题思路
两个指针，他们之间相隔n节点，一个节点到尾部了，那么另一个节点的下一个节点就是要被删除的节点。

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
    
        ListNode first = head;
        ListNode last = head;
        for (int i=0;i<n;i++) {
            last = last.next;
        }
        while(last!=null && last.next!= null){
            last = last.next;
            first = first.next;
        }

        if (first == head && last == null) {
            return head.next;
        }
        ListNode thr = first.next;
        first.next = thr.next;
        thr.next = null;
        return head;
    }
}
```