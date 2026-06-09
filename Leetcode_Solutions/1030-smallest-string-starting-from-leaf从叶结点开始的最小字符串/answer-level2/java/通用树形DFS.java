```
class Solution {
    private String ans = "~";
    private StringBuilder tmp = new StringBuilder();

    public String smallestFromLeaf(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode node) {
        if (node == null) {
            return;
        }
        tmp.append((char) ('a' + node.val));
        if (node.left == null && node.right == null) {
            String tmpStr = tmp.reverse().toString();
            ans = tmpStr.compareTo(ans) < 0 ? tmpStr : ans;
            tmp.reverse();
        }
        if (node.left != null) {
            dfs(node.left);
        }
        if (node.right != null) {
            dfs(node.right);
        }
        tmp.deleteCharAt(tmp.length() - 1);
    }
}
```
