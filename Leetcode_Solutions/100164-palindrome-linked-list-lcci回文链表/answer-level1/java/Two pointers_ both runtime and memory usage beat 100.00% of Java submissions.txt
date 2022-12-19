### 解题思路
Two pointers
reverse second half of linked list;
compare the first half and second half;

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
        if (head == null || head.next == null) 
            return true;
        ListNode slow = head;
        ListNode fast = head;

        // two pointers
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode prev = null;
        // reverse the second half of list
        while(slow != null ){
            // use a temporary next to store the next node
            ListNode next = slow.next;
            slow.next = prev;
            prev = slow;
            slow = next;
        }

        // compare reversed list and first half
        // if list has odd number of nodes: prev will have more nodes than head but the while condition takes care of that
        while (prev != null && head != null) {
            if (prev.val != head.val) 
                return false;
            prev = prev.next;
            head = head.next;
        }
        return true;        
    }
}
```