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
    int max = 0 ,i = 0;
    public int maxDepth(TreeNode root) {
        maxDep(root,i);
        return max;
    }
    
    void maxDep(TreeNode root,int i){
        if(root == null){
            max = Math.max(max,i);
            return;
        }
        //System.out.println(i);
        maxDep(root.left,i+1);
        maxDep(root.right,i+1);
    }
}
```