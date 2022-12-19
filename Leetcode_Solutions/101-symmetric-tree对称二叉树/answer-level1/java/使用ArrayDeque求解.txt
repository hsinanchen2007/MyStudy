### 解题思路
使用ArrayDeque去存储还未进行比较的节点。

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
        //对root首先进行分析
        if(root == null)
            return true;
        if(root.left == null && root.right == null)
            return true;
        if(root.left == null || root.right == null)
            return false;

        // 此时说明root有两个非空的左右子树    
        Deque<TreeNode> deqNode = new ArrayDeque<>();
        // 根节点的左孩子进去
        deqNode.addLast(root.left);
        // 根节点的右孩子进去
        deqNode.addLast(root.right);
        while(!deqNode.isEmpty()){
            // 如此可取，因为我们是成双成对地把节点压入ArrayDeque的
            TreeNode rightNode = deqNode.removeLast();
            TreeNode leftNode = deqNode.removeLast();
            // 对应的两个节点处的值不同，返回错误，结束
            if(leftNode.val != rightNode.val)
                return false;

            // 左节点的左孩子、右节点的右孩子是一对
            if(leftNode.left == null && rightNode.right == null ){
            
            }
            else if(leftNode.left == null || rightNode.right == null){
                return false;
            }
            else{
                // 注意添加的顺序，要与提取时呼应
                deqNode.addLast(leftNode.left);
                deqNode.addLast(rightNode.right);
            }

            // 左节点的右孩子、右节点的左孩子是一对
            if(leftNode.right == null && rightNode.left == null){

            }
            else if(leftNode.right == null || rightNode.left == null){
                return false;
            }
            else{
                deqNode.addLast(leftNode.right);
                deqNode.addLast(rightNode.left);
            }
        }
        // 出得了循环说明正确！
        return true;
    }
}


```