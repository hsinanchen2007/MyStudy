### 解题思路
此处撰写解题思路
思路和判断子树是否存在类似。
遍历树，如果有和head节点一直的，就开始执行匹配操作
注意一：
明显树中的值是可重复的，也就是有可能出现左子节点和右子节点值一样的情况。
匹配操作也是深度优先的思想。
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
    
    public boolean isSubPath(ListNode head, TreeNode root) {
        if (head == null) {
            return false;
        }
        dfs(root, head);
        return res;
    }
    private boolean res = false;

    private void dfs(TreeNode node, ListNode head) {
        if (res) {
            return;
        }
        if (node == null) {
            return;
        }
        if (node.val == head.val) {
            if (match(node, head)) {
                res = true;
                return;
            }
        }
        dfs(node.left, head);
        dfs(node.right, head);
    }

    private boolean match(TreeNode t, ListNode l) {
        if (l == null) {
            return true;
        }
        if (t == null) {
            return false;
        }
        if (t.val == l.val) {
            return match(t.left, l.next) || match(t.right, l.next);
        } else {
            return false;
        }
    }
}
```