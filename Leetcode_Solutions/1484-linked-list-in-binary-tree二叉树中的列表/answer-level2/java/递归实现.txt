### 解题思路
分别对当前节点和子节点进行递归

### 代码

```java
class Solution {
    public boolean isSubPath(ListNode head, TreeNode root) {
        if (head == null) {
            return true;
        }
        if (root == null) {
            return false;
        }
        return hasSubPath(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
    }

    public boolean hasSubPath(ListNode head, TreeNode root) {
        if (head == null) {
            return true;
        } 
        if (root == null) {
            return false;
        }
        if (root.val != head.val) {
            return false;
        } 
        return (hasSubPath(head.next, root.left) || hasSubPath(head.next, root.right));
    }
}
```