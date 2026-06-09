### 解题思路
回溯 当遍历到null则退出 否则取树节点的值到list中

核心在于用level记录下当前的层次 在res中通过level索引追加元素。
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(res, root, 0);
        return res;
    }

    private void dfs(List<List<Integer>> res, TreeNode root, int level){
        if (root == null){
            return;
        }
        if (level == res.size() || res.get(level) == null){
            res.add(new ArrayList<>());
        }
        if (root != null){
            res.get(level).add(root.val);
        }
        dfs(res, root.left, level + 1);
        dfs(res, root.right, level + 1);
    }
}
```