### 解题思路
使用if else应该更容易理解


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
        // 小技巧，第一个节点的值可以不返回，直接返回result.next
        ListNode result = new ListNode(0);
        ListNode data = result;
        int pre = 0;
        int val;
        while (true) {
            if (l1 == null) {
                if (l2 == null) {
                    break;
                } else {
                    val = l2.val + pre;
                }
            } else {
                if (l2 == null) {
                    val = l1.val + pre;
                } else {
                    val = l1.val + l2.val + pre;
                }
            }
            if (val > 9) {
                pre = 1;
                val = val - 10;
            } else {
                pre = 0;
            }
            data.next = new ListNode(val);
            data = data.next;
            l1 = l1 == null ? l1 : l1.next;
            l2 = l2 == null ? l2 : l2.next;
        }
        if (pre != 0) {
            data.next = new ListNode(pre);
        }
        return result.next;
    }
}
```