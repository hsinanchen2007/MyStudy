### 同判断 B 是不是 A 的子树

我的代码好像比榜一多了一小坨...

```
class Solution {
    private boolean res = false;

    public boolean isSubPath(ListNode head, TreeNode root) {
        if (head == null && root == null) {
            return true;
        }
        return dfs(root, head);
    }

    private boolean dfs(TreeNode root, ListNode head) {
        if (root != null) {
            if (root.val == head.val) {
                res = isSub(root, head);
            }
            if (!res) {
                return dfs(root.left, head) || dfs(root.right, head);
            } else {
                return true;
            }
        }
        return false;
    }

    private boolean isSub(TreeNode root, ListNode head) {
        if (root == null) {
            return head == null;
        }
        if (head == null) {
            return true;
        }
        return root.val == head.val && (isSub(root.left, head.next) || isSub(root.right, head.next));
    }
}
```
