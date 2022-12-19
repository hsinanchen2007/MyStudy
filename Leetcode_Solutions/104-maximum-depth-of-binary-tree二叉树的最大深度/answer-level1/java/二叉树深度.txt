### 解题思路
见 [面试题55-I](https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/solution/er-cha-shu-shen-du-di-gui-shuang-bai-by-hlhfev/)

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
    private int depth=0;
    public int maxDepth(TreeNode root) {
        search(root,0);
        return this.depth;
    }

    private void search(TreeNode root,int depth){
        if(root==null){
            return;
        }
        this.depth=Math.max(this.depth,depth+1);
        search(root.left,depth+1);
        search(root.right,depth+1);
    }
}
```