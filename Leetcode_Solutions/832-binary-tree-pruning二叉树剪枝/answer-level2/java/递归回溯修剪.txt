1. 所谓修剪就是把原本指向该节点的引用置 null；
2. 因此深度优先遍历到叶子节点，从叶子节点进行修剪，若剪掉叶子节点就返回 null；
3. 先修剪左子树再修剪右子树，当修剪完子树之后回溯到当前节点的时候需要判断：经过修剪之后该节点是否变成叶子节点是否满足修剪条件；因此代码里有两行重复的判断语句。
```
class Solution {
    public TreeNode pruneTree(TreeNode root) {
        // 先去掉叶子节点
        if(root.val == 0 && root.left == null && root.right == null )return null;
        // 修剪左子树
        if(root.left != null)
            root.left = pruneTree(root.left);
        // 修剪右子树
        if(root.right != null)
            root.right = pruneTree(root.right);
        // 回溯修剪，若去掉就只修剪叶子节点，回溯的时候不会修剪
        if(root.val == 0 && root.left == null && root.right == null )return null;
        return root;
    }
}
```
