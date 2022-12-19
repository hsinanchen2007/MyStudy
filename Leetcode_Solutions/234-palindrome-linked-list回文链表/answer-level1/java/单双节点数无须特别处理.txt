### 解题思路
基本思路就是使用快慢指针找到中间位置来截断链表，然后将后半部分链表反转；然后循环比较。
节点存在单复数：
- 单数节点的时候”线段“是双数，这时候慢指针刚好停在最中间节点；这个时候最中间的节点不用关心，从下一个节点开始作为后半部没分链表；反转后和前半部分对比。（前半部分多一个节点，循环后半部分即可）
- 双数节点的时候”线段“是单数，这时候满指针刚好停在第n/2 个节点；这个时候后半部分也应该从慢指针的下一个节点开始。。。。

总结来说后半部分链表从满指针的后一个节点开始即可。

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
        if(head==null) return true;
        ListNode fast = head, slow =head;
        while(fast!=null && fast.next!=null && fast.next.next!=null){
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode middle = slow.next;
        slow.next = null;

        middle = reverseList(middle);

        while(middle!=null){
            if(middle.val!=head.val){
                return false;
            }
            middle = middle.next;
            head = head.next;
        }
        return true;
        
    }

    public ListNode reverseList(ListNode head) {        
        ListNode pre = null;
        ListNode curr = head;
        while(curr!=null){
            ListNode nextTemp = curr.next;
            curr.next = pre;
            pre = curr;
            curr = nextTemp;
        }
        return pre;
    }
}
```