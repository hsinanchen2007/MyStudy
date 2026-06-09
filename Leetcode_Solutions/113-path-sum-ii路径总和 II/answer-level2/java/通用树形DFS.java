```
class Solution {
    private List<List<Integer>> ansList = new ArrayList<>();
    private List<Integer> tmpList = new ArrayList<>();

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        dfs(root, sum);
        return ansList;
    }

    private void dfs(TreeNode node, int sum) {
        if (node == null) {
            return;
        }
        tmpList.add(node.val);
        sum -= node.val;
        if (node.left == null && node.right == null && sum == 0) {
            ansList.add(new ArrayList<>(tmpList));
        }
        if (node.left != null) {
            dfs(node.left, sum);
        }
        if (node.right != null) {
            dfs(node.right, sum);
        }
        tmpList.remove(tmpList.size() - 1);
    }
}
```
