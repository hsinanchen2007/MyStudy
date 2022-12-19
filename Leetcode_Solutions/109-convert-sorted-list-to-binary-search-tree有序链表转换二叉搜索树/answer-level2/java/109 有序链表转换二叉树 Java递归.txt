### 解题思路
递归来写，至于递归的思路还是之前说的三步走，真的百试百灵。
1、找到终止条件
2、假设递归函数以及将后面的都完成了
3、处理第一个情况。

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
        if(head == null)
            return null;
        if(head.next == null)
            return new TreeNode(head.val);
        ListNode leftHead = head;
        //找到中间节点得值
        ListNode mid = head;
        ListNode preMid = head;
        ListNode fast = head;
        while(fast != null && fast.next != null && fast.next.next !=null){
            if(fast == null || fast.next == null || fast.next.next == null)
                break;
            mid = mid.next;
            fast = fast.next.next;
            if(mid != head.next)
                preMid = preMid.next;
        }
        if(preMid == mid){
            //只有两个节点得特殊情况
            TreeNode root = new TreeNode(leftHead.next.val);
            leftHead.next = null;
            root.left = sortedListToBST(leftHead);
            return root;
        }else{
            preMid.next = null;
            TreeNode root = new TreeNode(mid.val);
            root.left = sortedListToBST(leftHead);
            root.right = sortedListToBST(mid.next);
            return root;
        }
    }
}
```