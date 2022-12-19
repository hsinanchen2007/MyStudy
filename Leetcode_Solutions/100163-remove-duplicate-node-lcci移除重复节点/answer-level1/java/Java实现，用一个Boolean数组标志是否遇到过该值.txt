用一个Boolean数组来标志遇到的值，下次再遇到通过cnt数组得知，注意节点的值为[0, 20000]。
pre节点指向上一个节点，cur负责找到下一个没有重复过的节点，更新pre.next = cur。
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
    public ListNode removeDuplicateNodes(ListNode head) {
        if (head == null || head.next == null)
            return head;
        boolean[] cnt = new boolean[20000 + 1];
        cnt[head.val] = true;
        ListNode cur = head.next, pre = head;
        while (cur != null) {
            while (cur != null && cnt[cur.val])
                cur = cur.next;
            pre.next = cur;
            if (cur != null) {
                cnt[cur.val] = true;
                pre = cur;
                cur = cur.next;
            }
        }
        
        return head;
    }
    
}
```
