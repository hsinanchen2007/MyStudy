### 解题思路
此处撰写解题思路

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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode dummyhead = new ListNode(0);
        dummyhead.next = head;
        ListNode pre = dummyhead;
        ListNode cur = head;
        int count = 0;
        while (cur.next != null) {
            if (cur.val==cur.next.val&&cur.next.next==null){
                pre.next = null;
                break;
            }
            if (cur.next.val == cur.val) {
                cur = cur.next;
                count++;
            } else {
                if (count == 0) {
                    pre = cur;
                    cur = cur.next;
                } else {
                    cur = cur.next;
                    pre.next = cur;
                    count = 0;
                }

            }

        }
        return dummyhead.next;
        
    }
}
```