![image.png](https://pic.leetcode-cn.com/08bf674324dacfb1835a9f244b1b61bc110f0fbc9dffe7b6987060854dbf0cd2-image.png)


思路： 

当一号玩家完成了选择，把其余二叉树节点分成3部分：左孩子节点及其子孙节点，右孩子节点及其子孙节点，父节点及其他。如果有一个区域的节点数大于另外两个区域的节点数，那么二号玩家能赢。

```java []
class Solution {
    private TreeNode firstPlayerNode = null; //第一个玩家选择的节点
    private int leftChildrenNodeCount = 0; // 第一个玩家选择的节点为基准，左孩子及子孙节点数
    private int rightChildrenNodeCount = 0; // 第一个玩家选择的节点为基准，右孩子及子孙节点数
    
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        if (root == null) {
            return false;
        }
        findTreeNode(root, x); // 遍历寻找一号玩家选择的节点
        leftRecursionPreloaderTraversal(firstPlayerNode.left); // 计算一号玩家选择的节点左树区域的节点数
        rightRecursionPreloaderTraversal(firstPlayerNode.right); // 计算一号玩家选择的节点右树区域的节点数

        int parentNodeCount = n - leftChildrenNodeCount - rightChildrenNodeCount - 1; // 计算一号玩家选择的节点父节点区域的节点数
        return parentNodeCount > (n >> 1) || leftChildrenNodeCount > (n >> 1) || rightChildrenNodeCount > (n >> 1);
    }
    
    private void findTreeNode(TreeNode root, int x) {
        if (root == null) {
            return;
        }
        if (root.val == x) {
            firstPlayerNode = root;
            return;
        }
        findTreeNode(root.left, x);
        findTreeNode(root.right, x);
    }

    private void leftRecursionPreloaderTraversal(TreeNode root) {
        if (root != null) {
            leftChildrenNodeCount++;
            leftRecursionPreloaderTraversal(root.left);
            leftRecursionPreloaderTraversal(root.right);
        }
    }

    private void rightRecursionPreloaderTraversal(TreeNode root) {
        if (root != null) {
            rightChildrenNodeCount++;
            rightRecursionPreloaderTraversal(root.left);
            rightRecursionPreloaderTraversal(root.right);
        }
    }
}
```

