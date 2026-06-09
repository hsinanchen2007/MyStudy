```java
class Solution {
    private List<Integer> result = new ArrayList<>();
    public List<Integer> largestValues(TreeNode root) {
        recursion(root, 0);
        return result;
    }

    public void recursion(TreeNode root, int level) {
        if (root == null) {
            return;
        }
        if (result.size() == level) {
            result.add(root.val);
        } else {
            result.set(level, Math.max(result.get(level), root.val));
        }
        recursion(root.left, level + 1);
        recursion(root.right, level + 1);
    }
}
```
