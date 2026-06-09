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
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<>();
        if (root != null) {
            List<Integer> route = new ArrayList<>();
            pathSum(root, sum, 0, res, route);
        }
        return res;
    }

    private void pathSum(TreeNode cur, int sum, int now, List<List<Integer>> res, List<Integer> route) {
        now += cur.val;
        route.add(cur.val);
        if (cur.left == null && cur.right == null) {
            if (now == sum)
                res.add(new ArrayList(route));
        } else {
            if (cur.left != null)
                pathSum(cur.left, sum, now, res, route);
            if (cur.right != null)
                pathSum(cur.right, sum, now, res, route);
        }
        route.remove(route.size() - 1);
    }
}
```