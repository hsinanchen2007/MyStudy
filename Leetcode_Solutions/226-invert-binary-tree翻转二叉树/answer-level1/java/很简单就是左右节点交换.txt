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
    public TreeNode invertTree(TreeNode root) {
        //递归实现
        if(root == null)return null;
        TreeNode leftNode = root.left;
        TreeNode rightNode = root.right;
        root.left = rightNode;
        root.right = leftNode;
        invertTree(leftNode);
        invertTree(rightNode);
        return root;

         //通过层序遍历交换左右位置
        /*Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty()){
            TreeNode pollNode = queue.poll();
            TreeNode leftNode = pollNode.left;
            TreeNode rightNode = pollNode.right;
            pollNode.left = rightNode;
            pollNode.right = leftNode;
            if(leftNode != null){
                queue.offer(leftNode);
            }
            if(rightNode != null){
                queue.offer(rightNode);
            }
        }
        return root;*/
    }
}
```