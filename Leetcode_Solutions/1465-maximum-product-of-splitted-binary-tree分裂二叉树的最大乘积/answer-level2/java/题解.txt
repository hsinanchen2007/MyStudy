### 解题思路
一次dfs将每个节点的子树和算出来，再循环一次找到最大值
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
    List<Integer> l = new ArrayList<>();
    public int maxProduct(TreeNode root) {
        if (root == null) return 0;
        long allSum = dfsSum(root);
        long res = -1;
        for (int i = 0; i < l.size(); i++) {
            res = Math.max(res, (allSum - l.get(i)) * l.get(i));
        }
        return (int)(res % (1e9 +7));
    }
    int dfsSum(TreeNode t) {
        if (t == null) return 0;
        int sum = t.val + dfsSum(t.left) + dfsSum(t.right);
        l.add(sum);
        return sum;
    }
}
```