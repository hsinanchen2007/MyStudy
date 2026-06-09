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
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        ListNode tmp = head;
        int count = 0;
        while (tmp != null) {
            tmp = tmp.next;
            ++count;
        }
        count /= 2;
        tmp = head;
        while (count-- > 0)  {
            tmp = tmp.next;
        }

        ListNode pre = null;
        ListNode cur = tmp;
        ListNode next;

        while(cur != null) {
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }

        while (pre != null && head != null) {
            if (pre.val != head.val) {
                return false;
            }
            pre = pre.next;
            head = head.next;
        }
        return true;
    }
}
```