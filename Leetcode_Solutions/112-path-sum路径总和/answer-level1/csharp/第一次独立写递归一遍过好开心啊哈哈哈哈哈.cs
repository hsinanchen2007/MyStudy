### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/3b0f51af8c1391f1267c7e64c036f7db02268bf161a35eebbe01b0796273ba35-image.png)

### 代码

```csharp
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public bool HasPathSum(TreeNode root, int sum) {

        if(root == null){
            return false;
        }


        if(root.left == null && root.right == null){
            if(root.val == sum){
                return true;
            }else{
                return false;
            }
        }

        bool HasLeft = HasPathSum(root.left, sum- root.val);
        bool HasRight = HasPathSum(root.right, sum- root.val);

        return HasLeft||HasRight;
    }
}
```