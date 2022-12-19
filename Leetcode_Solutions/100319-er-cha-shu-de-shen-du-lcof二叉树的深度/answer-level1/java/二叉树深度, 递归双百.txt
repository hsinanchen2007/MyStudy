![l.png](https://pic.leetcode-cn.com/b045a6c41b369875f3ad66bae566a226ef6a0b055fe8cb2047fb440c1b13245d-l.png)


### 解题思路
递归，每到一层更新深度

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