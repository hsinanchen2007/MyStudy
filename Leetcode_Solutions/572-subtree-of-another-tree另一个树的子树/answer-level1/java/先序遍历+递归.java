```java
class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if (isIdentical(s, t)) {
            return true;
        }
        if (s != null) {
            return isSubtree(s.left, t) || isSubtree(s.right, t);
        }
        return false;
    }

    private boolean isIdentical(TreeNode s, TreeNode t) {
        if (s == null && t == null) {
            return true;
        }
        if (s == null || t == null) {
            return false;
        }
        return s.val == t.val && isIdentical(s.left, t.left) && isIdentical(s.right, t.right);
    }

}
```
