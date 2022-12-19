### 解题思路
因为这个链表不能进行翻转，所以就用栈来解决； 

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
        ListNode dummyHead = new ListNode(0);
        ListNode result = dummyHead;

        Stack<ListNode> s1 = new Stack();
        Stack<ListNode> s2 = new Stack();
        Stack<ListNode> resStack = new Stack();
        
        while (l1 != null) {
            s1.push(l1);
            l1 = l1.next;
        }
        while (l2 != null) {
            s2.push(l2);
            l2 = l2.next;
        }
        int carry = 0;
        while (!s1.isEmpty() || !s2.isEmpty()) {
            int add = carry;

            if (!s1.isEmpty()) {
                add += s1.pop().val;
            }
            if (!s2.isEmpty()) {
                add += s2.pop().val;
            }
            carry = add / 10;
            resStack.push(new ListNode(add % 10));
        }
        if (carry > 0) {
            resStack.push(new ListNode(carry));
        }
        while (!resStack.isEmpty()) {
            result.next = resStack.pop();
            result = result.next;
        }
        return dummyHead.next;
        


        // ListNode dummyHead = new ListNode(0);
        // ListNode result = dummyHead;

        // Stack<ListNode> s1 = new Stack();
        // Stack<ListNode> s2 = new Stack();
        // while (l1 != null) {
        //     s1.push(l1);
        //     l1 = l1.next;
        // }
        // while (l2 != null) {
        //     s2.push(l2);
        //     l2 = l2.next;
        // }
        // int carry = 0;
        // while (!s1.isEmpty() || !s2.isEmpty()) {
        //     int add = carry;

        //     if (!s1.isEmpty()) {
        //         add += s1.pop().val;
        //     }
        //     if (!s2.isEmpty()) {
        //         add += s2.pop().val;
        //     }
        //     carry = add / 10;
        //     result.next = new ListNode(add % 10);
        //     result = result.next;

        // }
        // if (carry > 0) {
        //     result.next = new ListNode(carry);
        // }
        // //翻转链表
        // return reverseListNode(dummyHead.next);
    }
    private static ListNode reverseListNode(ListNode cur) {
        ListNode rev = null;
        while (cur != null) {
            ListNode temp = cur.next;
            cur.next = rev;
            rev = cur;
            cur = temp;
        }
        return rev;
    }
}
```