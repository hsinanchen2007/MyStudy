### 解题思路
本题就是定义了**两个结点指针**`pre`和`cur`一前一后依次遍历整个链表
 
- `cur`结点指针率先出发，如果**没有遇见重复元素**则两个结点指针都向后移动一个位置

- 如果**遇见重复元素**，且`cur.next`不为`null`时，先用`while`循环**将重复的结点遍历到最后**，此时`cur`指的就是重复元素的最后一位置

- 然后用`pre`结点指针指向`cur`的下一个位置即**将最后一个重复元素断链**，然后继续遍历下去

- 最后返回`dummy`结点之后的元素即可。

### 代码

```java []
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
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy;
        ListNode cur = head;
        while (cur != null) {   
            // 判断重复元素
            if (cur.next != null && cur.val == cur.next.val) {
                // 如果重复元素有多个就使用 while 循环遍历到重复元素的最后一个
                while (cur.next != null && cur.val == cur.next.val) {
                    cur = cur.next;
                }   
                // 此时 cur 指的是重复元素的最后一个数，使用 pre 将其断链
                pre.next = cur.next;
                cur = pre.next;
            } else {
                // 没有遇到重复元素就像后继续遍历
                cur = cur.next;
                pre = pre.next;
            }                           
        }
        return dummy.next;
    }
}
```