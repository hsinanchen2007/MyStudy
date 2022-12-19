### 解题思路

直接上步骤：

1、快慢指针，找出链表的中间结点    
2、反转中间结点之后的链表    
3、将前半部分链表与反转后的后半部分链表元素挨个对比，如果元素有不相等的，则不是对称；否则，对称。

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
        if(head == null){
            return true;
        }

        if(head.next == null) {
            return true;
        }

        ListNode slow = head;
        ListNode fast = head.next;

        while(fast != null){
            fast = fast.next;
            if(fast != null){
                fast = fast.next;
            }

            slow = slow.next;
        }

        //此时 slow 为链表中间位置，将后半部分反转
        ListNode revertedHead = revert(slow);
        //对比前半部分和反转后的 后半部分
        while(head != null && revertedHead != null){
            if(head.val != revertedHead.val){
                return false;
            }
            head = head.next;
            revertedHead = revertedHead.next;
        }
        
        return true;
    }

    private ListNode revert(ListNode head){
        ListNode pre = null;
        ListNode current = head;

        while(current != null){
            ListNode temp = current.next;
            current.next = pre;
            pre = current;
            current = temp;
        }

        return pre;
    }
}
```