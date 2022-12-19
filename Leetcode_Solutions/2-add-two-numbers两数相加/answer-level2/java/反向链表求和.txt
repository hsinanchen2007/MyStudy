### 解题思路
初始节点dummy
当前节点current
进位数carry
逐步相加，出循环条件就是l1没了，l2没了，carry也不等于0了

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
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) {
            int dlg = ((l1 == null) ? 0 : l1.val) + ((l2 == null) ? 0 : l2.val) + carry;
            int value = dlg % 10;
            carry = dlg / 10;
            current.next =  new ListNode(value);
            current = current.next;

            l1 = (l1 == null) ? l1 : l1.next;
            l2 = (l2 == null) ? l2 : l2.next;            
        }
        return dummy.next;
    }
}
```