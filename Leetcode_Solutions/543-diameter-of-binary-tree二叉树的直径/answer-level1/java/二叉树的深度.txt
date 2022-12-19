### 解题思路
最大直径不一定过根节点,直径=左子树的深度+右子树的深度 最大直径为max(直径)
以每一个节点计算左子树与右子树的深度,取最大值即为最大直径

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
    //定义最大直径
    int result=0;
    public int diameterOfBinaryTree(TreeNode root) {
        
        depth(root);
        return result;
    }
    private int depth(TreeNode root){
        //节点为空,返回0
        if(root==null){
            return 0;
        }
        //计算左子树深度
        int left=depth(root.left);
        //计算右子树深度
        int right=depth(root.right);
        //取最大直径
        result=Math.max(result,left+right);
        //不为空返回左右节点的递归后各自+1的最大值（1表示这一层有数据),表示已对应节点的最大深度
        return Math.max(left,right)+1;
    }
}
```