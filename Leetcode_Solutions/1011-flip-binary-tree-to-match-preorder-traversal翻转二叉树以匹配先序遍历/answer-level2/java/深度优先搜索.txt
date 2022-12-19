```java
class Solution {
    private List<Integer> list;
    private int i;
    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        if (root == null) {
            return Collections.emptyList();
        }
        list = new ArrayList<>();
        if (dfs(root, voyage)) {
            return list;
        }
        return Collections.singletonList(-1);
    }

    private boolean dfs(TreeNode root, int[] voyage) {
        if (root == null) {
            return true;
        }
        if (root.val == voyage[i]) {
            i++;
            int temp = i;
            if (dfs(root.left, voyage) && dfs(root.right, voyage)) {
                return true;
            } else {
                i = temp;
                if (dfs(root.right, voyage) && dfs(root.left, voyage)) {
                    list.add(root.val);
                    return true;
                }
            }
        }
        return false;
    }
}
```
