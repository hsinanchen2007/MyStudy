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
    public boolean isSymmetric(TreeNode root) {
        if(root==null || (root.left==null && root.right==null)){
            return true;
        }
        if(root.left==null || root.right==null){
            return false;
        }
        Queue<TreeNode> leftQueue=new LinkedList<>();
        Queue<TreeNode> rightQueue=new LinkedList<>();
        leftQueue.add(root.left);
        rightQueue.add(root.right);
        while(!leftQueue.isEmpty()&&!rightQueue.isEmpty()){
            TreeNode leftTmp=  leftQueue.poll();
            TreeNode rightTmp=rightQueue.poll();
            if(leftTmp==null && rightTmp ==null){
                continue;
            }
            if((leftTmp==null && rightTmp!=null)||(leftTmp!=null && rightTmp==null)){
                return false;
            }
            if(leftTmp.val!=rightTmp.val){
                return false;
            }
            leftQueue.add(leftTmp.left);
            leftQueue.add(leftTmp.right);
            rightQueue.add(rightTmp.right);
            rightQueue.add(rightTmp.left);
        }
        return leftQueue.isEmpty()&&rightQueue.isEmpty();
    }
}
```