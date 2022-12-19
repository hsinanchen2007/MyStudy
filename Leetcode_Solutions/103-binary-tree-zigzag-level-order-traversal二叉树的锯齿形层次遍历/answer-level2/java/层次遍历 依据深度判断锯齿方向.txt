level % 2 判断锯齿方向

```
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> lists = new ArrayList<>();
        bfs(root, 0, lists);
        return lists;
    }

    public void bfs(TreeNode node, int level, List<List<Integer>> lists) {
        if (node == null) {
            return;
        }
        if (level == lists.size()){
            lists.add(new ArrayList<Integer>());
        }
        List<Integer> l = lists.get(level);
        if (level % 2 == 0){
            l.add(node.val);
        }else {
            l.add(0, node.val);
        }
        bfs(node.left, level + 1, lists);
        bfs(node.right, level + 1, lists);
    }
}
```

