### 解题思路
此处撰写解题思路
另写一个方法来判断左右节点是否对称
接着判断对应的子节点是否对称
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
    public boolean isSymmetric(TreeNode root) {
        if(root == null){
            return true;
        }
        return symetric(root.left, root.right);
    }

    /**
     * 另写一个方法来判断左右节点是否对称
     * 接着判断对应的子节点是否对称
     */
    public boolean symetric(TreeNode leftNode, TreeNode rightNode){
        // 判断节点是否对称
        if(leftNode == null && rightNode == null){
           return true; 
        } else if(leftNode != null && rightNode == null){
            return false;
        } else if(leftNode == null && rightNode != null){
            return false;
        } else if(leftNode != null && rightNode != null){
            if(leftNode.val != rightNode.val){
                return false;
            }
        }
        // 列出左右节点
        TreeNode childLeftOfLeftNode = leftNode.left; 
        TreeNode childRightOfLeftNode = leftNode.right; 
        TreeNode childLeftOfRightNode = rightNode.left; 
        TreeNode childRightOfRightNode = rightNode.right; 
        // 判断子节点是否对应
        return symetric(childLeftOfLeftNode, childRightOfRightNode)
            &&  symetric(childRightOfLeftNode, childLeftOfRightNode);

    }
}
```