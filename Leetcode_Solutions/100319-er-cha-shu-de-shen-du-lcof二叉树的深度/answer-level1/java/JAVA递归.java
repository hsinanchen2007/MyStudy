### 解题思路
递归遍历

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
    int max=1;
    int a=1;
    public int maxDepth(TreeNode root) {
        if(root==null)return 0;
        bianli(root,1);
        return max;
    }
    public void bianli(TreeNode root,int sd){
        if(root.left!=null){
           a=sd+1;
           bianli(root.left,a);
        }
        if(root.right!=null){
           a=sd+1;
           bianli(root.right,a); 
        }
        if(max<a) max=a;
    }
}
```