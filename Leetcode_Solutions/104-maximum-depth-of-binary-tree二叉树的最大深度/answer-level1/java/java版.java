### 解题思路
参考求解二叉树的深度

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
    public int maxDepth(TreeNode root) {
        if(root==null) return 0;
        Deque<TreeNode> queue=new LinkedList<TreeNode>();
        queue.offer(root);
        TreeNode levelLast=root;
        int maxDepth=0;
        while(!queue.isEmpty()){
            TreeNode node=queue.poll();
            if(node.left!=null) queue.offer(node.left);
            if(node.right!=null) queue.offer(node.right);
            if(node==levelLast){
                levelLast=queue.peekLast();
                ++maxDepth;
            }
        }
        return maxDepth;
    }
}
```