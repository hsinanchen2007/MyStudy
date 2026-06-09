### 解题思路
递归方法，先进入，在返回的时候对每个节点的val进行处理。
time：O(n) 
space：O(n) // n个栈帧

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

    private int carry;

    public ListNode plusOne(ListNode head) {
        carry = plus(head);
        if (carry == 1) {
            ListNode pre = new ListNode(carry);
            pre.next = head;
            return pre;
        }
        return head;
    }

    private int plus(ListNode head) {
        if (head == null)
            return 1;
        carry = plus(head.next);
        head.val += carry;
        carry = head.val / 10;
        head.val %= 10;
        return carry;
    }
}
```