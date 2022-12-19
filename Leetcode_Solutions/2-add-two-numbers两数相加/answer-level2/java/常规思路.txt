### 解题思路
先遍历链表得到真正的数字，因为数字太大，用BigInteger进行加和，最后把结果倒着组成链表

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
 import java.math.BigInteger;
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1.val == 0 && l1.next==null && l2.val != 0) return l2;
        if (l1.val != 0 && l2.val == 0 && l2.next==null) return l1;
        if (l1.val == 0 &&l1.next==null && l2.val == 0 && l2.next==null) return new ListNode(0);


        ListNode head1 = null;
        ListNode next1 = null;

        while (l1 != null) {
            next1 = l1.next;
            l1.next = head1;
            head1 = l1;
            l1 = next1;
        }

        StringBuilder sb1 = new StringBuilder();
        while (head1 != null) {
            sb1.append(head1.val);
            head1 = head1.next;
        }


        ListNode head2 = null;
        ListNode next2 = null;

        while (l2 != null) {
            next2 = l2.next;
            l2.next = head2;
            head2 = l2;
            l2 = next2;
        }

        StringBuilder sb2 = new StringBuilder();
        while (head2 != null) {
            sb2.append(head2.val);
            head2 = head2.next;
        }


        BigInteger b1 = new BigInteger(sb1.toString());

        BigInteger b2 = new BigInteger(sb2.toString());

        BigInteger sum = b1.add(b2);

        String str = sum.toString();
        ListNode result = null;
        for (int i = 0; i < str.length(); i++) {

            int a = Integer.parseInt(String.valueOf(str.charAt(i)));
            ListNode tmp = new ListNode(a);
            tmp.next = result;
            result = tmp;
        }

        return result;
    }
}
```