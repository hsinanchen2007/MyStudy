### 解题思路
没状态了，一道回溯改来改去

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

    int sum1;
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        sum1 = sum;
        List<Integer> now = new ArrayList<>();
        dfs(root, now, 0);
        return res;
    }

    void dfs(TreeNode cur, List<Integer> now, int sum2) {
        if (cur == null) return;
        now.add(cur.val);
        sum2 += cur.val;
        if (sum2 == sum1 && cur.left == null && cur.right == null) {
            res.add(new ArrayList<>(now));
        }
        dfs(cur.left, now, sum2);
        dfs(cur.right, now, sum2);
        now.remove(now.size() - 1);
    }
}
```