
```
class Solution {
    public int maxDepth(TreeNode root) {
        return iterator(root, 0);
    }
    
    public int iterator(TreeNode node, int count) {
        if(node == null) {
            return count;
        }
        count++;
        int a = iterator(node.left, count);
        int b = iterator(node.right, count);
        return a > b ? a : b;
    }
}
```
