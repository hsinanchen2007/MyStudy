### 解题思路
回文串的意思是正反相同 按正常理解我们只需要将当前链表反转在和原链表比较即可，但题目有个要求 空间复杂度为o(1)，这样代表我们不能使用格外空间，那我们换个思路，其实我们的本意是看该链表正反是否相同，那我们是不是只要找到中间节点，然后反转后续的节点就可以了，这样空间复杂度为o(1)

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
    public boolean isPalindrome(ListNode head) {
         if (head == null) {
            return true;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }


        //代表奇数节点
        if (fast != null) {
            slow = slow.next;
        }

        ListNode tailNode = reverse(slow);

        while (head != null && tailNode != null) {
            if (head.val != tailNode.val) {
                return false;
            }

            head = head.next;
            tailNode = tailNode.next;
        }

        return true;
    }

     private ListNode reverse (ListNode head) {
        ListNode cur = head;
        ListNode pre = null;
        while (cur != null) {
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
}
```