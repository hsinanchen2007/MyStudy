### 解题思路
**新建两条链表，一条是顺序链表，一条反转后的，顺序比较各个位置的节点值是否相等，因为回文数反转后和原来是一样的****
### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode  {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
       int a=val;
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {

          ListNode dummy = new ListNode(0);
        ListNode reverse = null;
        ListNode cur = dummy;

        ListNode tmp1 = null;
        ListNode tmp2 = null;
        while (head != null) {
            tmp1 = new ListNode(head.val);
            tmp2 = new ListNode(head.val);

            //正序链表
            cur.next = tmp1;
            cur = tmp1;

            //反转链表
            tmp2.next = reverse;
            reverse = tmp2;

            head=head.next;

        }

       // System.out.println(ListNode.toString(reverse));
        dummy = dummy.next;//正序链表
        reverse = reverse;// 反转链表

        boolean flag = true;

        while (dummy != null || reverse != null) {

            if (dummy.val != reverse.val) return false;
            dummy = dummy.next;
            reverse = reverse.next;

        }

        return flag;

    




    }
}
```