### 解题思路
暴力法，先遍历HeadA中的元素temp;然后用temp和HeadB中的元素逐个比较。
不过比较的条件不是值相等，而是两个node是否相同。
另外，因为HeadB中遍历会到末尾，但下一次HeadA新的元素比较时，需要从HeadB开头比较。
所以遍历HeadB时需要用其他元素来保存遍历的节点。
另外要注意特殊条件，没有相交的时候返回null.

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
        if (headA == null) {
                return null;
            }
            if (headB == null) {
                return null;
            }
            while (headA != null) {
                ListNode newHead=headB;
                int temp = headA.val;
                while (newHead != null) {
                    if (headA == newHead ) {
//                    if (temp == headB.val ) {
                        return newHead;
                    } else {
                        newHead = newHead.next;
                    }
                }
                headA = headA.next;
            }
            return null;
    }
}
```