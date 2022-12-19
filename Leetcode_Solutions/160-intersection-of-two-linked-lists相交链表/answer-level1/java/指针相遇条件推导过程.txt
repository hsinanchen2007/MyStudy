### 解题思路

 * c 为公共的长度，A 链表长度 a = a1 + c，B 链表长度 b = b1 + c
 * 为了抵消公共长度 c 做减法后 a-b = a1-b1
 * 代码指针走路，只能做加法了，转换为：a + b1 = b + a1
 * 最终思路为，A 走完自己的路后开始走 b1，B 走完自己的路后开始走 a1，指针相遇为公共节点起始位置

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
     public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        ListNode a = headA;
        ListNode b = headB;
        while (a != b) {
            a = (a == null) ? headB : a.next;
            b = (b == null) ? headA : b.next;
        }
        return a;
    }
}
```