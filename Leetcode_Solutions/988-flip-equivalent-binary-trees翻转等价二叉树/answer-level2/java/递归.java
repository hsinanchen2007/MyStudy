```java
class Solution {
    public boolean flipEquiv(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) {
            return true;
        }
        if (t1 == null || t2 == null) {
            return false;
        }
        if (t1.val != t2.val) {
            return false;
        }
        return (flipEquiv(t1.left, t2.left) && flipEquiv(t1.right, t2.right)) ||
                (flipEquiv(t1.left, t2.right) && flipEquiv(t1.right, t2.left));
    }
}
```
