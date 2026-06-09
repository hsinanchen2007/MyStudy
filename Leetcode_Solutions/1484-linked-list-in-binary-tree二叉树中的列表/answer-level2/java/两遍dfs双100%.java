第一遍dfs找起点
第二遍dfs根据根据起点找路径

为什么一边dfs不行，因为二叉树每一个节点都可以是链表的起点，所以需要枚举每一个值与链表头的值相同的节点为起点

```
class Solution {
    boolean res = false;
    public boolean isSubPath(ListNode head, TreeNode root) {
        findPath(root,head);
        return res;
    }
    public void findPath(TreeNode root, ListNode head){
        if(root==null) return;
        if(res) return;
        if(root.val == head.val) dfs(root,head);
        findPath(root.right,head);
        findPath(root.left,head);
    }
    public void dfs(TreeNode root,ListNode head){
        if(head==null){
            res = true;
            return;
        }
        if(root==null||res){
            return;
        }
        if(root.val!=head.val) return;
        dfs(root.right, head.next);
        dfs(root.left, head.next);
    }
}
```
