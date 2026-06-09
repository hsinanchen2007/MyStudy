class Solution {
    private int maxDepth = 0;
    public int maxDepth(Node root) {
        dfs(root,0);
        return maxDepth;
    }
    public void dfs(Node node,int n) {
        if (node == null) return;
        maxDepth = Math.max(maxDepth,++n);
        for (int i = 0; i < node.children.size(); i++) {
            dfs(node.children.get(i),n);
        }
    }
}