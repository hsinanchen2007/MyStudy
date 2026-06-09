### 解题思路
1 先申请一个队列，把根节点加入对列中。
2 从左到右按层遍历二叉树，遍历到当前节点时开始交换当前节点左右节点的位置。
3 交换完成后把交换位置后的左右节点加入队列，继续进行while循环，直到队列为空。

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
    public TreeNode mirrorTree(TreeNode root) {
        if(root==null) return null;
        Queue<TreeNode> queue=new LinkedList<TreeNode>();
        queue.add(root);
        while(!queue.isEmpty()){
            TreeNode node=queue.poll();
            convert(node);//交换左右节点的位置
            if(node.left!=null) queue.add(node.left);
            if(node.right!=null) queue.add(node.right);
        }
        return root;
    }
    public void convert(TreeNode node){
        TreeNode temp=node.left;
        node.left=node.right;
        node.right=temp;
    }
}
```