### 解题思路
此处撰写解题思路
本题可以分解为几个简单题的组合
1. 找出链表的中间结点
2. 反转链表
3. 比较两个链表是否所有结点都一致
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
        ListNode fast = head;
        ListNode slow = head;
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode middleHead = reverseList(slow);
        while (middleHead != null && head != null){
            if(middleHead.val == head.val){
                middleHead = middleHead.next;
                head = head.next;
            }else {
                return false;
            }
        }
        return true;
    }

    public ListNode reverseList(ListNode head){
        if(head == null || head.next == null) {
            return head;
        }
        ListNode p = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return p;
    }
}
```