### 解题思路
通过序号的奇偶数来是否进行反转，当遇到偶数时才进行反转，关键是反转的过程中要把上上个节点指向后面反转过来的节点

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
    public ListNode swapPairs(ListNode head) {
        if(head == null) return null;
        if(head.next == null) return head;
        int i = 0;
        ListNode cur = head;
        //记录变更后的第一个节点
        ListNode newHead = head.next;
        //左边节点
        ListNode left = null;
        //右边节点
        ListNode right;
        //上上个节点
        ListNode prePreNode = null;
        while (cur != null) {
            i++;
            if (i % 2 == 1) {
                //奇数时把当前节点更新为左节点
                left = cur;
                cur = cur.next;
            } else if (i % 2 == 0) {
                //偶数时把当前节点更新为右节点
                right = cur;
                cur = cur.next;

                //左右节点下个节点变换
                //左边的下个节点为右边的下一个节点
                left.next = right.next;
             
                //右边的下个节点为左边节点
                right.next = left;

                //上上个节点下个节点指向右边节点（这个右边节点其实是交换后的左节点了）
                if (prePreNode != null) {
                    prePreNode.next = right;
                }
                //更新上上节点的下个节点（这个右边节点其实是交换后的左节点了）
                prePreNode = left;
            }
        }
        return newHead;
    }
}
```