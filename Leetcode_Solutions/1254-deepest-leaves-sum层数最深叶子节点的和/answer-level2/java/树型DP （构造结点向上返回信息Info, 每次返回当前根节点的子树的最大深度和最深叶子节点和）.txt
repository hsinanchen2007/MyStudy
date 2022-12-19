```
class Info {
    public int depth;
    public int deepestSum;
    public Info(int d, int ds) {
        depth = d;
        deepestSum = ds;
    }
    public Info() {}
}
class Solution {
    public int deepestLeavesSum(TreeNode root) {
        Info info = helper(root, 1);
        return info.deepestSum;
    }
    public Info helper(TreeNode node, int level) {
        if (node.left == null && node.right == null) {
            return new Info(level, node.val);
        }
        Info linfo = new Info();
        Info rinfo = new Info();
        if (node.left != null)
            linfo = helper(node.left, level + 1);
        if (node.right != null)
            rinfo = helper(node.right, level + 1);
        if (linfo.depth > rinfo.depth)
            return new Info(linfo.depth, linfo.deepestSum);
        else if (linfo.depth < rinfo.depth)
            return new Info(rinfo.depth, rinfo.deepestSum);
        else
            return new Info(linfo.depth, linfo.deepestSum + rinfo.deepestSum);
    }
}
```
