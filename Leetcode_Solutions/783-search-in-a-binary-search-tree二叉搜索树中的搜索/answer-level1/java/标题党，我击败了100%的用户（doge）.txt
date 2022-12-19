### 解题思路
此处撰写解题思路
中序，验证是否升序
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
    public TreeNode searchBST(TreeNode root, int val) {
        if(root==null) return null;

        while(root!=null){
            if(root.val<val){
                root = root.right;
            }else if(root.val>val){
                root=root.left;
            }else if(root.val == val)return root;
         }
            return null;
            
        
    }

    
}
```