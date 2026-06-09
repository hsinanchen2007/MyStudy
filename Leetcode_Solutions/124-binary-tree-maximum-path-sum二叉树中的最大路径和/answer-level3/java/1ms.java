### 解题思路
此处撰写解题思路

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
    int max = Integer.MIN_VALUE;    //最大路径和
    public int maxPathSum(TreeNode root) {
        max(root);
        return max;
    }
    //从下往上
    public int max(TreeNode node){
        if(node == null) return 0;
        int left = max(node.left);      //左子树最大路径
        int right = max(node.right);    //右子树最大路径
        max = Math.max(max,left + node.val + right);//设置当前节点是最高节点
        return Math.max(0,Math.max(node.val + left, node.val + right)); //当前节点不是最高节点，返回父结点
    }
}
```