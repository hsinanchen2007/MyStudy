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
    public int kthSmallest(TreeNode root, int k) {
        if (k <= 0) {
            return 0;
        }
        List<Integer> list = new ArrayList<>();
        parse(list, root);
        return list.get(k - 1);
    }

    private void parse(List<Integer> result, TreeNode root) {

        if (result == null || root == null) {
            return;
        }
        parse(result, root.left);
        result.add(root.val);
        parse(result, root.right);
    }
}
```