### 解题思路
把树的左子树生成镜像树，和右子树进行对比

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
        if(root==null){
            return true;
        }
        //做一次判断
        if(root.left==null&&root.right==null){
            return true;
        }else if((root.left==null&&root.right!=null)||(root.left!=null&&root.right==null)){
            return false;
        }else if(root.left.val!=root.right.val){
            return false;
        }
        return compare(mirror(root.left),root.right);
    }

    //生成镜像树
    public TreeNode mirror(TreeNode root){
        TreeNode node;
        if(root.left!=null){
            mirror(root.left);
        }
        if(root.right!=null){
            mirror(root.right);
        }
        node = root.left;
        root.left = root.right;
        root.right = node;
        return root;
    }

    //对比两棵树是否相似
    public boolean compare(TreeNode p,TreeNode q){
        if(p==null&&q==null){
            return true;
        }else if((p==null&&q!=null)||(p!=null&&q==null)){
            return false;
        }else if(p.val!=q.val){
            return false;
        }
        return compare(p.left,q.left)&&compare(p.right,q.right);
    }
}
```