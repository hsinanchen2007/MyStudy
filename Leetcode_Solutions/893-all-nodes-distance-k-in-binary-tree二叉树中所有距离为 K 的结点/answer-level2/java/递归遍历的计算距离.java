首先遍历一遍二叉树保存根节点到target节点的路径，记为targetPath。接下来再次遍历二叉树，遍历的过程中用tmpPath记录根节点到当前访问的节点的路径，要求当前节点到target节点的距离，本质上是求当前节点和target节点到它们的最近公共祖先的距离和。而二者的最近公共祖先通过比较targetPath和tmpPath可以得出。这里用一个变量pos来记录每次访问得到的最近公共祖先的位置，这样就不需要每次都从头开始比较targetPath和tmpPath了。时间复杂度降为O(n)。
```
class Solution {
    List<TreeNode> targetPath = new ArrayList<>();
    int pos = 0;
    List<Integer> res = new ArrayList<>();
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        findTargetPath(root, target);
        traverse(root, new ArrayList<>(), K);
        return res;
    }

    private void traverse(TreeNode root, List<TreeNode> tmpPath, int K) {
        if (root == null) return;
        tmpPath.add(root);
        int initPos = pos;
        if (pos < targetPath.size() && targetPath.get(pos) == root) pos++;
        int distance = targetPath.size() + tmpPath.size() - 2*pos;
        if (distance == K) res.add(root.val);
        traverse(root.left, tmpPath, K);
        traverse(root.right, tmpPath, K);
        tmpPath.remove(tmpPath.size()-1);
        pos = initPos;
    }

    private boolean findTargetPath(TreeNode root, TreeNode targetNode) {
        if (root == targetNode) {
            targetPath.add(root);
            return true;
        }
        if (root == null) return false;
        targetPath.add(root);
        if (findTargetPath(root.left, targetNode))
            return true;
        if (findTargetPath(root.right, targetNode))
            return true;
        targetPath.remove(targetPath.size()-1);
        return false;
    }
}
```
