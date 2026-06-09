### 解题思路
1.沿着左子树列表反转，和单链表反转类似。
2.沿着新的左子树遍历，把左孩子的右子树指针赋值给当前节点的右孩子。
3.交换当前节点的左右子树。
4.往交换后的右子树转移（这个其实就是之前的左孩子，只是因为交换了，所以变成了右孩子）。

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        if (root == null){
            return null;
        }
        // 1.树沿着左子树反转
        TreeNode curNode = root;
        TreeNode prevNode = null;
        // 开始反转
        while (curNode != null){
            TreeNode nextNode = curNode.left;// 缓存原来的左孩子
            curNode.left = prevNode;// 左孩子反转
            prevNode = curNode;// 前置指针后移
            curNode = nextNode;// 当前指针后移
        }
        root = prevNode;
        // 这时候curNode是反转完之后的头节点了
        curNode = root;
        while (curNode.left != null){
            // 2.现在左孩子的右子树，变成自己的右子树
            curNode.right = curNode.left.right;
            curNode.left.right = null;// 之前的指针置空
            // 3.交换左右子树
            changeChild(curNode);
            curNode = curNode.right;// 这里为什么是right呢，因为左右节点被交换了
        }
        return root;
    }
    
    /**
     * 交换左右子树
     * @param node
     */
    private void changeChild(TreeNode node){
        if (node == null){
            return;
        }
        TreeNode temp = node.left;
        node.left = node.right;
        node.right = temp;
    }
}
```