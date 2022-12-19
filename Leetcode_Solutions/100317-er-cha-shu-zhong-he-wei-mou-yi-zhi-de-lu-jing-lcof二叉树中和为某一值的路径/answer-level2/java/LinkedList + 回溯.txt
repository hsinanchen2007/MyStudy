```java
class Solution {
    private List<List<Integer>> res = new LinkedList<>();
    private LinkedList<Integer> list = new LinkedList<>();
    private int target;

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        target = sum;
        dfs(root, 0);
        return res;
    }

    private void dfs(TreeNode root, int cur_sum) {
        if (root != null) {
            int val = root.val;
            list.addLast(val);
            cur_sum += val;
            if (cur_sum == target && root.left == null && root.right == null)
                res.add(new LinkedList<>(list));
            else {
                dfs(root.left, cur_sum);
                dfs(root.right, cur_sum);
            }
            list.removeLast();
        }
    }
}
```
