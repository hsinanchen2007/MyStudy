### 解题思路
递归

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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
         if(postorder.length==0||inorder.length==0)
          {
              return null;
          }
          int nums=postorder[postorder.length-1];
          int i;
          for(i=0;i<inorder.length;i++)
          {
             if(inorder[i]==nums)
             {
                 break;
             }
          }
          

          
     TreeNode root=new TreeNode(nums);

    root.left=buildTree(Arrays.copyOfRange(inorder,0,i),Arrays.copyOfRange(postorder,0,i));
    root.right=buildTree(Arrays.copyOfRange(inorder,i+1,inorder.length),Arrays.copyOfRange(postorder,i,inorder.length-1));
          return root;



    }
}
```