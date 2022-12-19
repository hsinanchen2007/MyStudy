### 解题思路
![屏幕快照 2020-02-27 17.19.38.png](https://pic.leetcode-cn.com/7c24411b82b04276c5b0e636220310517bf65af43ce58c7d2196e1896704e53d-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-27%2017.19.38.png)


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
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null) {
            return res;
        }
        dfs(root, new ArrayList<>(), sum);
        return res;
    }

    private void dfs(TreeNode node, List<Integer> list, int sum) {
        list.add(node.val);
        if (sum - node.val == 0 && node.left == null && node.right == null) {
            res.add(new ArrayList<>(list));
            return;
        }
        if (node.left != null) {
            dfs(node.left, list, sum - node.val);
            list.remove(list.size() - 1);
        }
        if (node.right != null) {
            dfs(node.right,list, sum - node.val);
            list.remove(list.size() - 1);
        }
    }
}
```