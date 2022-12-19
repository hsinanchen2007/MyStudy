**解题思路：**
设置一个全局变量，用以保存当前参与比较的结点。
整体是回文数的条件为：
    ①每次回溯，当前结点与回溯到的结点值相等。
    ②之前回溯的结果为真。
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

    private ListNode cur;

    public boolean isPalindrome(ListNode head) {

        if (head == null) return true;

        this.cur = head;

        return compare(head);
    }

    public boolean compare(ListNode head) {

        if (head.next == null) {
            return head.val == this.cur.val;
        }

        boolean a = compare(head.next);
        this.cur = this.cur.next;
        boolean b = head.val == this.cur.val;

        return a && b;
    }
}
```
时间复杂度：O(n)
空间复杂度：O(n)