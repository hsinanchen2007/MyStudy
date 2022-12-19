### 解题思路
使用快慢指针，需要注意的是空链表和单节点的链表是符合条件的！

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

        if(head==null) return true;

        ListNode slow = head;
        ListNode fast = head;

        //左边反转后的头节点
        ListNode reverse = null;
        ListNode tmp=null;

        while (fast != null && fast.next != null ) {

                slow = slow.next;
            fast = fast.next.next;

            //左边进行反转
              tmp = head.next;
            head.next = reverse;
            reverse = head;
            head = tmp;
        }



        if (fast != null) {
            slow = slow.next;
        }

        //System.out.println("slow = "+ListNode.toString(slow));
        // System.out.println("reverse = " + reverse);

        while (slow != null && reverse != null) {

            if (slow.val != reverse.val) return false;
            slow=slow.next;
            reverse=reverse.next;
        }

        return true;




    }
}
```