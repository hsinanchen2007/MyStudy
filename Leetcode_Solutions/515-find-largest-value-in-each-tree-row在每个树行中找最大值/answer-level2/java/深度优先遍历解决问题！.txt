### 解题思路
![屏幕快照 2020-03-01 13.13.22.png](https://pic.leetcode-cn.com/017e9a7b6d760775d41d605b315a561d17f9754b60abd9462d0d49b4ba1d7551-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-01%2013.13.22.png)


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
    List<Integer> res = new ArrayList<>();
    public List<Integer> largestValues(TreeNode root) {
        if (root == null) {
            return res;
        }
        dfs(root, 0);
        return res;
    }

    private void dfs(TreeNode node, int level) {
        if (node == null) {
            return;
        }
        if (res.size() == level) {
            res.add(node.val);
        } else {
            res.set(level, Math.max(res.get(level), node.val));
        }
        dfs(node.left, level + 1);
        dfs(node.right, level + 1);
    }
}
```