### 解题思路
三个指针。一个pre重复区域的前一个，cur和next用来遍历所有的重复区域，next指向重复区域的下一个；
不重复的地方，直接pre=cur;

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
        if (head == null || head.next == null) {
            return head;
        }
        ListNode tummy = new ListNode(0);
        tummy.next = head;
        ListNode pre = tummy;
        while (pre.next != null) {
            ListNode cur = pre.next;
            if (cur.next != null) {
                ListNode next = cur.next;
                if (next.val == cur.val) {
                    boolean flag = false;
                    while (next.val == cur.val) {
                        if (next.next != null) {
                            cur = cur.next;
                            next = next.next;
                        } else {
                            flag = true;
                            break;
                        }
                    }

                    pre.next = flag ? null : next;
                } else {
                    pre = cur;
                }
            } else {
                break;
            }
        }
        return tummy.next;
    }
}
```