### 解题思路
![屏幕快照 2020-02-29 16.46.54.png](https://pic.leetcode-cn.com/9a9d21cf6fbf4cc7fcf728ac9e39f9d7fd15530cd98dc144509c5090cefe7c70-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-29%2016.46.54.png)


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

    public List<List<Integer>> levelOrder(TreeNode root) {
        dfs(root, 0);
        for (int i = 1; i < res.size(); i+=2) {
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < res.get(i).size(); j++) {
                list.add(res.get(i).get(res.get(i).size() - 1 - j));
            }
            res.set(i, list);
        }
        return res;
    }

    private void dfs(TreeNode node, int level) {
        if (node == null) {
            return;
        }
        if (res.size() == level) {
            List<Integer> list = new ArrayList<>();
            list.add(node.val);
            res.add(list);
        } else {
            res.get(level).add(node.val);
        }
        dfs(node.left, level + 1);
        dfs(node.right, level+ 1);
    }
}
```