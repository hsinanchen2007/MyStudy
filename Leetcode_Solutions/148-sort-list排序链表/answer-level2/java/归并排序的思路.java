### 解题思路
由于链表的缘故，合并时，只申请了常数个节点，这点与数组还是很不同的。

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
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode midListNode = getMidListNode(head);
        ListNode half = midListNode.next;
        //拆分链表
        midListNode.next = null;
        return merge(sortList(head),sortList(half));
    }

    public ListNode getMidListNode(ListNode head){
        if (head == null)
            return head;
        //快慢指针
        ListNode slow,fast;
        slow = fast = head;
        while (fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

    public ListNode merge(ListNode a, ListNode b){
        ListNode dummyHead, current;
        dummyHead = new ListNode(-1);
        current = dummyHead;
        while (a != null && b != null){
            if (a.val <= b.val){
                current.next = a;
                a = a.next;
            }
            else {
                current.next = b;
                b = b.next;
            }
            current = current.next;
        }
        current.next = (a == null) ?  b : a;
        return dummyHead.next;
    }
}
```