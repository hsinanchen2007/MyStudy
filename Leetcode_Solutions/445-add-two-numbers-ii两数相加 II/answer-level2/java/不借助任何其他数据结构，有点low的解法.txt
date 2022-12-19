### 解题思路
用最简单的指针，数学特性考虑，关键是要保留9的进位指针

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
        int k1  =0;
        ListNode h1 = l1;
        while (h1 != null) {
            h1 = h1.next;
            k1++;
        }
        int k2 = 0;
        ListNode h2 = l2;
        while (h2 != null) {
            h2 = h2.next;
            k2++;
        }
        if (k1 >= k2) {
            return addTwoNumbers( l1,  k1,  l2,  k2);
        } else {
            return addTwoNumbers( l2,  k2,  l1,  k1);
        }
    }

        public ListNode addTwoNumbers(ListNode l1, int k1, ListNode l2, int k2) {
            ListNode head = new ListNode(0);
            ListNode cur = head;
            ListNode cur9 = cur;
            for (int i = 0; i < k1; i++) {
                ListNode n1 = l1;
                ListNode n2 = i >= (k1 - k2) ? l2 : null;
                int sum = n1.val + (n2 != null ? n2.val : 0);
                int carry = sum / 10;
                ListNode now = new ListNode(sum % 10);
                cur.next = now;
                cur = cur.next;
                l1 = l1.next;
                if (n2 != null) {
                    l2 = l2.next;
                }
                if (carry == 0) {
                    if (cur.val != 9) {
                        cur9 = cur;
                    }
                } else {
                    cur9.val += 1;
                    while (cur9.next != null) {
                        cur9 = cur9.next;
                        if (cur9 != cur) {
                            cur9.val = 0;
                        }
                    }
                } 
            }


        return head.val == 0 ? head.next : head;
    }
}
```