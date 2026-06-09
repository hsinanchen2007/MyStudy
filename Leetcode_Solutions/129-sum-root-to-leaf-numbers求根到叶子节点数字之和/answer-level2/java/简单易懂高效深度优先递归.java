### 解题思路
深度优先遍历，到达叶节点便进行添加进结果中。

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
    int result = 0;
    public int sumNumbers(TreeNode root) {
        //为空时直接返回0
        if (root == null) return 0;
        dfs(root,0);
        return result;
    }

    public void dfs(TreeNode node,int current){
        //加上该节点的val
        current += node.val;
        //判断是否加入到结果中
        if (node.left == null && node.right == null) result += current;
        //左子树
        if (node.left != null) dfs(node.left,current*10);
        //右子树
        if (node.right != null) dfs(node.right,current*10);
    }
}
```