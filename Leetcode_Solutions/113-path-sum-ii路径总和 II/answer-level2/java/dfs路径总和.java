### 解题思路
通过一个动态数组记录根节点到当前节点的所有路径节点，若到了叶子节点，若满足题意则将存储的节点存储进结果
时间复杂度：O（n+h），h为树的高度
空间复杂度：O（n）

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
    LinkedList<Integer> list;
    List<List<Integer>> result;
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null ) {
            return new ArrayList<>();
        }
        list = new LinkedList<>();
        result = new ArrayList<>();
        dfs(root, 0, sum, new ArrayList<>());
        return result;
    }

    public void dfs(TreeNode node, int current, int sum, List<TreeNode> seen) {
        if (seen.contains(node)) {
            return;
        }
        seen.add(node);
        list.add(node.val);
        current += node.val;
        if (node.left == null && node.right == null) {
            if (current == sum) {
                insertList();
                list.removeLast();
            } else {
                list.removeLast();
            }
            return;
        } 
        if (node.left != null) {
            dfs(node.left, current, sum, seen);
        }
        if (node.right != null) {
            dfs(node.right, current, sum, seen);
        }
        list.removeLast();
    }
    public void insertList() {
        List<Integer> level = new ArrayList<>();
        for (Integer num:list) {
            level.add(num);
        }
        result.add(level);
    }
}
```