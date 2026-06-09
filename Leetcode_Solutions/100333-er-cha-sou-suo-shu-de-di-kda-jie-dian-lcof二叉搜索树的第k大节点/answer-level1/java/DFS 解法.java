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
 // 递归解法
class Solution {
    int count;;
    int result;
    public int kthLargest(TreeNode root, int k) {
        this.count = k;
        dfs(root);
        return result;
    }
    // 因为二叉搜索树的右子结点 大于 父节点 左子节点小于父节点
    // 所以 第k大从右节点开始遍历 同时应该从最大值开始返回 所以用dfs
    // 从最大值节点依次返回 如果不是第k大 计数器减一
    private void dfs(TreeNode root){
        if(root == null)
            return;
        dfs(root.right);
        if(count == 1){
            result = root.val;
            count--;
            return;
        }
        count--;
        dfs(root.left);
    }
}
```