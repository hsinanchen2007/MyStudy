```
class Solution {
    public int kthLargest(TreeNode root, int k) {
        List<Integer> nodes = new ArrayList<>();
        dfs(nodes,root);
        return nodes.get(nodes.size()-k);
    }

    public void dfs(List<Integer> nodes,TreeNode root){
        if(root == null) return;
        dfs(nodes,root.left);
        nodes.add(root.val);
        dfs(nodes,root.right);
    }
}
```
