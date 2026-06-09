### 解题思路
递归求深度，左右值差大于一返回false

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
    public boolean isBalanced(TreeNode root) {
        boolean flag =true;
        int[] a=new int[1];
        deep(root,a);
        if(a[0]==0){
            return true;
        }else{
            return false;
        }
    }

    public int deep(TreeNode root,int[] a){
        if(root==null){
            return 0;
        }

        int leftlen=deep(root.left,a);
        int rightlen=deep(root.right,a);
        if(Math.abs(leftlen-rightlen)>1){
            a[0]=1;
        }
        return Math.max(leftlen,rightlen)+1;


    }
}
```