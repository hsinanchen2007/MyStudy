### 解题思路
类似于二叉树的镜像，需要注意的是终止条件的判断

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
        return isDuicheng(root,root);
    }
    //依旧采用递归的思想
    public boolean isDuicheng(TreeNode A,TreeNode B){
        //当A和B都为null，说明递归终止
        if(A==null&&B==null){
            return true;
        }
        //当其中一个为null，说明二者不对称
        if(A==null||B==null){
            return false;
        }
        //当二者的值不相等时，也是不对称的
        if(A.val!=B.val){
            return false;
        }
        return isDuicheng(A.left,B.right)&&isDuicheng(A.right,B.left);
    }
}
```