### 解题思路
定义全局变量设置最大深度为0，递归遍历，每次往下一层的时候，深度+1

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
    int maxDepth = 0;
    public int maxDepth(TreeNode root) {
        if (root != null){
            getMaxDepth(root, 1);
        }
        return maxDepth;
    }
    private void getMaxDepth(TreeNode root, int deep){
        if (deep > maxDepth){
            maxDepth = deep;
        }
        if(root.left != null){
            getMaxDepth(root.left, deep + 1);
        }
        if(root.right != null){
            getMaxDepth(root.right, deep + 1);
        }
    }
}
```