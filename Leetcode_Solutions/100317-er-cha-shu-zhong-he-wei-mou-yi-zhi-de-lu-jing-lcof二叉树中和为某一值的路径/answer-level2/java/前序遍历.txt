### 解题思路

直接一次遍历就可以解出此题。

![image.png](https://pic.leetcode-cn.com/7fd16822141e6765cdcf712ba8fc76222fbcd5e4dbc628cba69b214dde6f0675-image.png)

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
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;
        List<Integer> cur = new ArrayList<>();
        pathSumTraverse(root, 0, sum, cur, result);
        return result;
    }

    private void pathSumTraverse(
            TreeNode node, int val, int sum,
            List<Integer> cur, List<List<Integer>> result) {
        val += node.val;
        cur.add(node.val);
        if (node.left == null && node.right == null && val == sum) {
            result.add(new ArrayList<>(cur));
        }
        if (node.left != null) pathSumTraverse(node.left, val, sum, cur, result);
        if (node.right != null) pathSumTraverse(node.right, val, sum, cur, result);

        cur.remove(cur.size() - 1);
    }
}
```