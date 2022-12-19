### 解题思路
寻找到中点后，记得断开中点前部分的链表。

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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null)
            return null;
        if (head.next == null)
            return new TreeNode(head.val);
        ListNode slow = head;
        ListNode fast = head;
        ListNode pre = head;
        //寻找中部节点
        //偶数时为后一个节点
        while (fast.next != null){
            fast = fast.next;
            pre = slow;
            slow = slow.next;
            if (fast.next != null)
                fast = fast.next;
        }
        //slow指向中部节点 pre指向该节点的前一个节点
        //前后链表断开
        pre.next = null;
        TreeNode root = new TreeNode(slow.val);
        root.left = sortedListToBST(head);
        root.right = sortedListToBST(slow.next);
        return root;
    }
}
```