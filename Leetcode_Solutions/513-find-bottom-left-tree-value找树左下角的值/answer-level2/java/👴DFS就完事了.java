直接无脑DFS。搜到叶子节点时，判断当前叶子节点是否是最深的，如果是则更新ans和max，最后返回ans。

需要注意的是应该优先搜左子树，以保证最后一层有多个叶子时，ans记录的是最左边的一个。

当然如果你喜欢先搜右子树也ok，把`h > max`给改成`h >= max`就行了，一回事儿哈。


```java
class Solution {
    private int ans = -1;
    //记录当前最大高度
    private int max = -1;

    public int findBottomLeftValue(TreeNode root) {
        dfs(root, 0);
        return ans;
    }

    private void dfs(TreeNode root, int h) {
        if(root == null) {
            return;
        }
        if(root.left == null && root.right == null) {
            if(h > max) {
                max = h;
                ans = root.val;
            }
        }
        dfs(root.left, h + 1);
        dfs(root.right, h + 1);
    }
}
```