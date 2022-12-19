### 解题思路
o(1)空间复杂度，不使用递归
假设原链表为 2-3-4-8-1-9-6
思路：1.获取链表长度
     2.长度范围内从1 2 4 8 16 ....的方式进行遍历
     3.每次遍历，按照2中的数值，比如当前遍历1，把原链表进行拆解，拆成2 3 4 8 1 9 6共7组，然后一一合并得到2-3-4-8-1-9-6
       假如遍历到2，则拆解为2-3 4-8 1-9 6共4组，然后两两合并，得到2-3-4-8-1-6-9，以此类推
关键词：排序链表合并 链表拆解 
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
    public ListNode sortList(ListNode head) {
        ListNode dummyHead = new ListNode(-911);
        dummyHead.next = head;

        ListNode p = head;
        int length = 0;
        while(p != null) {
            ++length;
            p = p.next;
        }

        for (int size = 1; size < length; size *= 2) {
            ListNode cur = dummyHead.next;
            ListNode tail = dummyHead;

            while (cur != null) {
                ListNode left = cur;
                ListNode right = cut(left, size);
                cur = cut(right, size);

                tail.next = merge(left, right);
                while (tail.next != null) {
                    tail = tail.next;
                }
            }
        }
        return dummyHead.next;
    }

    public ListNode cut(ListNode head, int size) {
        ListNode p = head;
        while(--size > 0 && p != null) {
            p = p.next;
        }
        if (p == null) return p;

        ListNode next = p.next;
        p.next = null;
        return next;
    }

    public ListNode merge(ListNode left, ListNode right) {
        ListNode dummyHead = new ListNode(-911);
        ListNode p = dummyHead;
        while(left != null && right != null) {
            if (left.val < right.val) {
                p.next = left;
                p = left;
                left = left.next;
            } else {
                p.next = right;
                p = right;
                right = right.next;
            }
        }
        p.next = left != null ? left : right;
        return dummyHead.next;
    }
}
```