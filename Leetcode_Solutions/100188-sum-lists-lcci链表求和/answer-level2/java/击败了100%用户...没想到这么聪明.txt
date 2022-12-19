### 解题思路
此处撰写解题思路
链表左对齐，从左到右，对位相加。当有进位时，就是大于等于10，下一次对位需要++
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();
        ListNode result = head;
        boolean preFlag = false;
        while(l1 != null || l2 != null || preFlag) {
            int tmp = (l1 == null ? 0:l1.val) + (l2 == null ? 0:l2.val);
            if (preFlag) {
                tmp++;
            }
            if(tmp >= 10) {
                preFlag = true;
            } else {
                preFlag = false;
            }
            result.next = new ListNode(tmp % 10);
            result = result.next;
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        }
        return head.next;
    }
}
```