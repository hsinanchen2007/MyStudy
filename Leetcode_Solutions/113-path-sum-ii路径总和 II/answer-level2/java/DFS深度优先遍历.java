### 解题思路
![image.png](https://pic.leetcode-cn.com/c8fa9305fc8bf7c2bcc04ac9d3620a23ae6c5d081d61458469676b78be7a2e99-image.png)


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
        if (root == null) {
            return res;
        }

        List<Integer> subsets = new ArrayList<>();
        subsets.add(root.val);
        dfs(root, sum, root.val, subsets, res);
        return res;
    }

    private void dfs(TreeNode root, int sum, int sumNow, List<Integer> subsets, List<List<Integer>> res) {
        if (root != null && root.left == null && root.right == null) {
            if (sumNow == sum) {
                res.add(new ArrayList<>(subsets));
            }
        }

        if (root.left != null) {
            sumNow += root.left.val;
            subsets.add(root.left.val);
            dfs(root.left, sum, sumNow, subsets, res);
            sumNow -= root.left.val;
            subsets.remove(subsets.size() - 1);
        }

        if (root.right != null) {
            sumNow += root.right.val;
            subsets.add(root.right.val);
            dfs(root.right, sum, sumNow, subsets, res);
            sumNow -= root.right.val;
            subsets.remove(subsets.size() - 1);
        }
    }
}
```