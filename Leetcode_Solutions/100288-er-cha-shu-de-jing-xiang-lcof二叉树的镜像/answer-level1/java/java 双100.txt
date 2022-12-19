### 解题思路
广度优先遍历

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
        Queue<TreeNode> queue=new LinkedList<TreeNode>();
        queue.add(root);
        while(!queue.isEmpty()){
           TreeNode tmp= queue.poll();
           if(tmp!=null){
               //左右子树互换
               TreeNode left=tmp.left;
               tmp.left=tmp.right;
               tmp.right=left;
                //如果不为null，则将之加入队列
               if(tmp.left!=null){
                    queue.add(tmp.left);
               }
               if(tmp.right!=null){
                    queue.add(tmp.right);
               }
           }
        }
        return root;
    }
}
```