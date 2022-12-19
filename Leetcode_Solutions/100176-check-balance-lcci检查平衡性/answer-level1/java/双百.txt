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
    boolean b=true;
    public boolean isBalanced(TreeNode root) {
        aa(root,0);
        return b;
    }
    public int aa(TreeNode root,int i){
        if(!b){
            return 0;
        }
        if(root==null){
            return i;
        }
        int left=aa(root.left,i+1);
        int right=aa(root.right,i+1);
        if(Math.abs(left-right)>1){
            b=false;
        }
        return Math.max(left,right);
    }
}
```