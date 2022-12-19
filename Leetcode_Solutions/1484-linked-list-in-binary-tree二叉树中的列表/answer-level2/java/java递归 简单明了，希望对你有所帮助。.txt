这道题和剑指offer第26题十分相似，都是判断一个结构是不是另一个的子结构。
那么就会有3种情况：
1链表是当前树的子结构
2链表是当前树左子树的子结构
3链表是当前树右子树的子结构。
```
    public boolean isSubPath(ListNode head, TreeNode root) {
        if(root == null) return false;
        return isSame(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right); 
    }

    private boolean isSame(ListNode head, TreeNode root){
        // head为空，说明链表都遍历完了。
        if(head == null) return true;
        // head不为空，但是root为空，说明树不够用了。
        if(root == null) return false;
        // 值不同，肯定不行。
        if(head.val != root.val) return false;
        return isSame(head.next, root.left) || isSame(head.next, root.right);
    }
```
