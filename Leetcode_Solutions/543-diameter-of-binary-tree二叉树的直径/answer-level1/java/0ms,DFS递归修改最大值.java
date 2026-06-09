### 解题思路
找深度是采用从下往上递归传值的方式.
同时每一层获取左子树和右子树的深度，两者相加和最大值max比较，取其中最大的就好。
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
       int max ;
    public Solution() {
        this.max = 0;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        findeepth(root);
        return max;
    }

    public int findeepth(TreeNode root){
        if (root==null){
            return 0;
        }
        int res = -1;
        int left = 0 ;
        int right = 0 ;
        /*假设已经递归到最底层*/
        if(root.left==null&&root.right==null){
            return  1 ;
        }
        for (int i = 0; i <2 ; i++) {
            if(i==0&&root.left!=null){
                left = findeepth(root.left);
                res  = left;
            }
            if(i==1&&root.right!=null){
                right = findeepth(root.right);
                res = Math.max(res,right);
            }
        }
        if (res>0){
            res+=1;
        }
        max = Math.max(max,left+right);
        return res;
    }

}
```