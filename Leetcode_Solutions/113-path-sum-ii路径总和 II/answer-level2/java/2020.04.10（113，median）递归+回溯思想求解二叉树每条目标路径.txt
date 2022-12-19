### 解题思路
本题使用**递归+回溯**的思想 `DFS` 遍历整个二叉树求出每条目标路径
    
- 首先创建 `ans` 结果集用来接收找到的目标路径，然后定义**递归方法** `path` 寻找每条路径上满足题意的路径

- 考虑特殊情况：只有**根节点**或者遍历到了**叶子结点**的时候，就将该临时路径数组 `tmp` 放入结果集中（每次都**初始**路径 `tmp`）

- 其他情况就按照**递归**的方法依次遍历左右子树各个结点

- 其中利用**回溯**思想将每次目标路径的数组元素**回退**到上一个结点，之后遍历另一条边的结点寻找更多的可能性

- 所有遍历结束返回结果集 `ans` 即可。

### 代码

```java []
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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> tmp = new ArrayList<>();
        // 递归求解路径总和
        path(root, sum, ans, tmp);
        return ans;        
    }
    
    // 传入4个参数来完成路径的存放和搜索
    private void path(TreeNode root, int sum, List<List<Integer>> ans, ArrayList<Integer> tmp) {
        if (root == null) {
            return;
        }
        tmp.add(root.val);
        // 如果只有根节点或只有叶子结点，则直接放入 ans 中
        if (root.left == null && root.right == null && sum == root.val) {
            // 这里使用 new 的形式是因为初始化后,传进来的数据每次都是更新后的 tmp
            ans.add(new ArrayList<>(tmp));
        }
        path(root.left, sum - root.val, ans, tmp);
        path(root.right, sum - root.val, ans, tmp);
        // 这里利用了回溯的思想:每次回退上一个节点再寻找另一条边的节点作为新路径
        tmp.remove(tmp.size() - 1);
    }
}
```