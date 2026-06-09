```java
class Solution {
    private Set<Integer> set = new HashSet<>();

    public boolean findTarget(TreeNode root, int target) {

        if (root == null) {
            return false;
        }
        int diff = target - root.val;
        if (set.contains(diff)) {
            return true;
        }
        set.add(root.val);
        return findTarget(root.left, target) || findTarget(root.right, target);
    }
}
```
