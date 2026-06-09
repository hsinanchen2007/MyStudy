执行用时 :1 ms, 在所有 java 提交中击败了99.94% 的用户
内存消耗 :35.9 MB, 在所有 java 提交中击败了82.66%的用户
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k < 1)
            return head;
        ListNode pre = head;
        int len = 0;
        while(pre != null){
            len++;
            pre = pre.next;
        }
        if(k >= len)
            k = k%len;
        if(k == 0)
            return head;
        pre = head;
        int count = len - k-1;
        while(count > 0){
            pre = pre.next;
            count--;
        }
        ListNode last = pre.next;
        ListNode headTemp = last;
        pre.next = null;
        while(last.next != null){
            last = last.next;
        }
        last.next = head;
        return headTemp;
    }
}
```
