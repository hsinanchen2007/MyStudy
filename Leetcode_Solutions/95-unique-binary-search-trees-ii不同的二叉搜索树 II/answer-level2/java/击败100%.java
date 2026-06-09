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
    public List<TreeNode> generateTrees(int n) {
        List<TreeNode> ret = new ArrayList<>();
        if(n == 0){
            return ret;
        }
        ret.addAll(generateTrees(1, n));
        return ret;       
    }
    // 包括start， end
    private List<TreeNode> generateTrees(int start, int end){
        // 
        List<TreeNode> ret = new ArrayList<>();
        if(start > end){
            return null;
        }
        
        for(int i = start; i <= end; i++){  
            List<TreeNode> leftAll = generateTrees(start, i-1);
            List<TreeNode> rightAll = generateTrees(i+1, end);
            if(leftAll == null && rightAll == null){
                TreeNode root = new TreeNode(i);
                root.left = null;
                root.right = null;
                ret.add(root);
                continue;
            }
            if(leftAll == null){
                for(TreeNode right : rightAll){
                    TreeNode root = new TreeNode(i);
                    root.right = right;
                    ret.add(root);
                }
                continue;
            }
            if(rightAll == null){
                for(TreeNode left : leftAll){
                    TreeNode root = new TreeNode(i);
                    root.left = left;
                    ret.add(root);
                }
                continue;                    
            }
            for(TreeNode left : leftAll){
                for(TreeNode right : rightAll){
                    TreeNode root = new TreeNode(i);
                    root.left = left;
                    root.right = right;
                    ret.add(root);
                }
            }
        }
        return ret;
    }
}
```