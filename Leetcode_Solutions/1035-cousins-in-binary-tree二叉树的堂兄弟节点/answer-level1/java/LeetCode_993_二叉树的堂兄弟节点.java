### 解题思路

#### 思路一：2ms 超越14%

**层次遍历**，每次比较同一个节点下的两个值是否等于x,y。如果等于，返回false，否则把每个层级的节点记录下来，看看是否包含xy,如果包含，返回true

#### 思路二：0ms 超越100%

**深度遍历**，分别定义两个node，表示x，y的父节点。在定义两个int变量，表示xy的深度，之后判断是否深度相同且**父节点不同**即可。

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
    
    TreeNode xParent;
    TreeNode yParent;
    int xHight;
    int yHight;
    public boolean isCousins(TreeNode root, int x, int y) {
        dfs(root, x, y, 0, null);
        return xHight == yHight && !xParent.equals(yParent);
    }

    private void dfs(TreeNode root, int x, int y, int deepth, TreeNode parent) {
        if (root == null) return;
        deepth ++;
        if (root.val == x) {
            xParent = parent;
            xHight = deepth;
        }

        if (root.val == y) {
            yParent = parent;
            yHight = deepth;
        }

        dfs(root.left, x, y, deepth, root);
        dfs(root.right, x, y, deepth, root);
    }
}
```