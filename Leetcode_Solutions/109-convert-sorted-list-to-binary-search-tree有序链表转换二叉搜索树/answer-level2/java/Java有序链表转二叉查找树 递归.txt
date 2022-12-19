### 解题思路
思路：先找到中间节点的前一个节点premid，然后用premid.next.val生成根节点,递归root.right=sortedListToBST（premid.next.next）, root.left=sortedListToBST（head）,注意找到的premid.next有可能为null，链表就剩一个节点，则只需要生成root。

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
        if(head==null){
           return null;
       }
       
       ListNode premid= findmid(head);
       TreeNode root=null;
       if(premid.next==null){
           root = new TreeNode(premid.val);
       }else{
           root = new TreeNode(premid.next.val);
           root.right = sortedListToBST(premid.next.next);
           premid.next = null;
           root.left = sortedListToBST(head);
       }
       
       
       return root;

    }
    public ListNode findmid(ListNode head){
        ListNode fast=head.next,slow=head,premid=head;
        while(fast!=null && fast.next!=null){
            fast=fast.next.next;
            premid=slow;
            slow=slow.next;
        }
        return premid;
    }
}
```