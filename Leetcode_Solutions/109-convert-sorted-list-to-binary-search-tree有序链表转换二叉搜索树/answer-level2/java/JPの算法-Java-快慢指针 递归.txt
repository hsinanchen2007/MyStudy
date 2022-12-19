```
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        if(head==null)
            return null;
        return dfs(head,null);
    }

    //快慢指针 递归找中点，中点就是根节点，然后在分别递归左右子树
    public TreeNode dfs(ListNode head,ListNode tail){
        if(head==tail)
            return null;
        ListNode slow = head;
        ListNode fast = head;
        //找中点,slow就是中点
        while(fast!=tail&&fast.next!=tail){
            slow = slow.next;
            fast = fast.next.next;
        }
        TreeNode mid = new TreeNode(slow.val);
        mid.left = dfs(head,slow);
        mid.right = dfs(slow.next,tail);
        return mid;
    }
}
```
