### 解题思路
1、递归求二叉树深度
2、中间过程判断是否是平衡树，如果不是，直接终止递归，返回-1

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
    public boolean isBalanced(TreeNode root) {
        return depth(root)!=-1;
    }

    /**
     * 求树深度算法
     * @param root 根节点
     * @return 如果左右子树高度差大于1，返回-1，否则返回0
     */
    private int depth(TreeNode root){
        if(root == null){
            return 0;
        }
        int left = depth(root.left);
        if(left == -1){
            return -1;
        }
        int right = depth(root.right);
        if(right == -1){
            return -1;
        }
        //加1代表加上根节点的高度
        return Math.abs(left-right)<2?Math.max(left,right)+1:-1;
    }
}
```