### 解题思路
1. 先设置一个全局变量maxDiff来保存最大差值,在深度优先遍历中不断得对它进行更新
2. 在dfs函数中max和min的初始值为Integer.MIN_VALUE和Integer.MAX_VALUE;递归终止条件是node==null,只有在此时才对maxDiff进行更新操作

### 代码

```java
public class Solution {
    // 保存最大相差值
    private int maxDiff;

    public int maxAncestorDiff(TreeNode root) {
        maxDiff = 0;
        dfs(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
        return maxDiff;
    }

    // DFS  对节点node进行深度优先遍历
    private void dfs(TreeNode node, int max, int min){
        if(node == null){
            // 只有到达叶节点之后才更新maxDiff
            maxDiff = Math.max(maxDiff, max-min);
            return;
        }

        max = Math.max(max, node.val);
        min = Math.min(min, node.val);

        dfs(node.left, max, min);
        dfs(node.right, max, min);
    }
}

```