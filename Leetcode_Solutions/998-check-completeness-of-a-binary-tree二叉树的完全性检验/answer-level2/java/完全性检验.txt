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
    public boolean isCompleteTree(TreeNode root) {
        if(root==null)return true;
        Queue<TreeNode> queue=new LinkedList<>();
        boolean leaf=false;
        TreeNode l=null;
        TreeNode r=null;
        queue.offer(root);
        while(!queue.isEmpty()){
            root=queue.poll();
            l=root.left;
            r=root.right;
            if((l==null&&r!=null)||(leaf&&(l!=null||r!=null)))return false;
            if(l!=null)queue.offer(l);
            if(r!=null)queue.offer(r);
            else leaf=true;
        }
        return true;

    }
}
```