### 解题思路
# 假如要求最长路径一定经过根节点，该怎么算
自然而然的思路：**最大长度 = 左子树的最大长度(深度) + 右子树的最大长度(深度)**
# 那怎么求解二叉树的深度呢？
自然而然的思路：递归
递归终止条件：根节点为null，返回0; 
递归体：**最大深度 = max（左子树的最大长度(深度) + 右子树的最大长度(深度)）+1**
# 但是题目要求二叉树的直径不一定经过根节点
思路：遍历每一个节点，计算一定经过该节点的最长路径即可
遍历使用递归
使用全局变量记录当前最大长度
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
    /*假如这条路径必须穿过根节点，则此算法是对的，即左子树最大长度+右子树最大长度
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null){
            return 0;
        }
        return maxLength(root.left) + maxLength(root.right);
    }
    public int maxLength(TreeNode node){
        if(node == null){
            return 0;
        }
        return Math.max(maxLength(node.left) + 1, maxLength(node.right) + 1);
    }
    */
    public int ans = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        maxLength(root);
        return ans;
    }

    public int maxLength(TreeNode node){
        if(node == null){
            return 0;
        }
        int leftLength = maxLength(node.left);//左子树深度
        int rightLength = maxLength(node.right);//右子树深度
        ans = Math.max(ans, leftLength + rightLength);//数的直径为左子树+右子树
        return Math.max(leftLength + 1, rightLength + 1);
    }
}
```