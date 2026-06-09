![image.png](https://pic.leetcode-cn.com/4b08d631542a53e0eb42c9983fa050e789bf7247909db59a88ef84758a15ec81-image.png)


### 解题思路
1. 首先用快慢指针找到根节点位置
2. 保留根节点前一个链表指针指向null
3. 递归创建树并返回

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
        if(head == null) return null;
        if(head.next == null){
            TreeNode root = new TreeNode(head.val);
            root.left = null;
            root.right = null;
            return root;
        }
        if(head.next.next == null){
            TreeNode root = new TreeNode(head.next.val);
            TreeNode left = new TreeNode(head.val);
            root.left = left;
            root.right = null;
            left.left = null;
            left.right = null;
            return root;
        }
        ListNode pre = new ListNode(0);
        pre.next = head;
        ListNode slow = pre;
        ListNode fast = pre;
        ListNode end = slow;
        slow = slow.next;
        fast = fast.next.next;
        while(fast != null){
            end = slow;
            if(slow != null) slow = slow.next;
            if(fast != null && fast.next != null) fast = fast.next.next;
            if(fast != null && fast.next == null) fast = fast.next;//这步针对fast走到末尾，上一步不执行出现死循环的情况
        }
        end.next = null;
        TreeNode root = new TreeNode(slow.val);
        root.left = sortedListToBST(pre.next);
        root.right = sortedListToBST(slow.next);
        return root;
    }
}
```