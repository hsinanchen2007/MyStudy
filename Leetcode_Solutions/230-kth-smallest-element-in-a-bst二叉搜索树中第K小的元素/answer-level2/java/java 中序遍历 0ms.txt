### 解题思路

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
    public int count=0,ans=0;
    public int kthSmallest(TreeNode root, int k) {
        inorder(root,k);
        return ans;       
    }
    public void inorder(TreeNode root,int k){//中序遍历，通过count记录是第几个
        if(root==null)
         return;
        if(root.left!=null)
         inorder(root.left,k);
        count++;
        if(count==k)
        {
         this.ans=root.val;
         return;
        }
        if(root.right!=null)
         inorder(root.right,k);
    }
}
```