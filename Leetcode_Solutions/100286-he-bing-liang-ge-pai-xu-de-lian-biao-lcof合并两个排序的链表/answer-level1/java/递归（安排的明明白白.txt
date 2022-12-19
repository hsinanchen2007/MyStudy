### 解题思路
l1:1->2->3
l2:1->3->4
两个链表已经是有序链表，标签打了分治，所以就考虑了递归的方法，看起来是归并排序的一种变形。
递归结束的条件就是两个链表的指针分别指向null
(1)如果l1.val<l2.val 则是l1.next继续和l2比较
(2)如果l1.val>=l2.val 则是l2.next继续和l1 比较

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
         if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
}
```