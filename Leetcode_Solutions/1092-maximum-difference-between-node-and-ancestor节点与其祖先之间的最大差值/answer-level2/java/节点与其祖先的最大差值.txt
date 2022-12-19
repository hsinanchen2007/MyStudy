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
    public int maxAncestorDiff(TreeNode root) {
        int left=maxAncestorDiff(root.left,root.val,root.val);
        int right=maxAncestorDiff(root.right,root.val,root.val);
        return left>right? left:right;
    }

    public int maxAncestorDiff(TreeNode root,int max, int min){
        if(root==null)
            return 0;
        if(root.val>max)  max=root.val;
        else if(root.val<min)  min=root.val;
        if(root.left==null&&root.right==null)
            return max-min;
        int left=maxAncestorDiff(root.left,max,min);
        int right=maxAncestorDiff(root.right,max,min);
        return left>right? left:right;
    }
}
```