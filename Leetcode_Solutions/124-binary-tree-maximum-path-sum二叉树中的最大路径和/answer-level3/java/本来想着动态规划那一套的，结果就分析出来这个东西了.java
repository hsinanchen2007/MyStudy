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
    private int max = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        //以当前节点的左路径或右路径的最大值作为状态
        //对于每一个节点都要判断左右路径的路径和是不是最大路径和
        max(root);
        return max;
    }
    
    public int max(TreeNode root){
        if(root == null) return 0;
        int left = max(root.left);
        int right = max(root.right);
        int temp_max = 0;
        int return_value = 0;
        if(left <= 0 && right <= 0){
            temp_max = root.val;
            return_value = root.val;
        }else if(left <= 0){
            temp_max = root.val + right;
            return_value = temp_max;
        }else if(right <= 0){
            temp_max = root.val + left;
            return_value = temp_max;
        }else{
            temp_max = root.val + left + right;
            return_value = left > right ? left + root.val : right + root.val;
        }
        if(temp_max > max) max = temp_max;
        return return_value;
    }
}
```