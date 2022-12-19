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
    int n=0;
    public int kthLargest(TreeNode root, int k) {

        int[] res=new int[1];
        res[0]= Integer.MIN_VALUE;
        middle(root,k,res);
        return res[0];
    }

    public void middle(TreeNode root,int k,int[] res){
        if(root ==null){
            return;

        }
        if(root.right!=null){

        middle(root.right,k,res);
        }
        n++;
        if(k==n){
            res[0]=root.val;
            return ;
        }
        if(root.left!=null){
                middle(root.left,k,res);
        }
        

        return ;
    }
}
```