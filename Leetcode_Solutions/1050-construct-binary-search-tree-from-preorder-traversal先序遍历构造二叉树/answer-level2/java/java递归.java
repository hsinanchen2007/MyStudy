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
    public TreeNode bstFromPreorder(int[] preorder) {
          if(preorder.length==0)
        {
            return null;
        }
        int num=preorder[0];
        int i;
        
        for(i=0;i<preorder.length;i++)
        {
            if(preorder[i]>num)
            {
                break;
            }
        }
        TreeNode root=new TreeNode(num);
        root.left=bstFromPreorder(Arrays.copyOfRange(preorder,1,i));
        root.right=bstFromPreorder(Arrays.copyOfRange(preorder,i,preorder.length));
    
        return root;
    }
}
```