### 解题思路
貌似绝大部分关于二叉树的题都是用递归吧，递归就完事了

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
        //求长度
        int length=0;
        ListNode cur=head;
        while(true){
            cur=cur.next;
            length++;
            if(cur==null)
                break;
        }
        if(length==1){
            return new TreeNode(head.val);
        }
        //下面建立树
        ListNode left_list=head;
        ListNode cur2=head;
        for(int i =0;i<length/2-1;i++){
            cur2=cur2.next;
        }
        TreeNode result=new TreeNode(cur2.next.val);
        ListNode right_list=cur2.next.next;
        cur2.next=null;
        TreeNode left_tree=sortedListToBST(left_list);
        TreeNode right_tree=sortedListToBST(right_list);
        result.left=left_tree;
        result.right=right_tree;
        return result;
    }
}
```