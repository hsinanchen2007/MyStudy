
![屏幕截图.jpg](https://pic.leetcode-cn.com/ac3212b81790abb8544901678ffb043a24e14d77c8f53a93e42a26e162b52f4e-%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.jpg)

深度优先搜索求解

```
class Solution {
    // 以每个节点作为起始节点来比较，直到找到匹配的
    public boolean isSubPath(ListNode head, TreeNode root) {
        if (dfs(root, head)) return true;
        if (root == null && head == null) return true;
        if (root == null && head != null) return false;
        return isSubPath(head, root.left) || isSubPath(head, root.right);
    }
    
    // 从起始节点开始，向下走，判断是否匹配
    public boolean dfs(TreeNode root, ListNode cur) {
        if (cur == null) return true;
        if (cur != null && root == null) return false;
        if (root.val != cur.val) return false;
        return dfs(root.left, cur.next) || dfs(root.right, cur.next);
    }
}
```
