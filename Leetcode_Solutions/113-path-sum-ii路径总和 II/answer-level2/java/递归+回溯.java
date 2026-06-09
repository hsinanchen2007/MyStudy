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
        List<Integer> list = new ArrayList<>();
        helper(root, sum, list, res);
        return res;
    }

    private void helper(TreeNode node, int sum, List<Integer> list,  List<List<Integer>> res) {
        if(node == null) {
            return;
        }

        sum = sum - node.val;
        list.add(node.val);
        if (node.left == null && node.right == null && sum == 0) {
            res.add(new ArrayList<>(list));
        } else {
            helper(node.left, sum, list, res);
            helper(node.right, sum, list, res);
        }
        list.remove(list.size() -1);
    }
}
```