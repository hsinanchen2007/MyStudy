### 解题思路
执行用时 :1 ms, 在所有 Java 提交中击败了99.61%的用户
首先层次遍历树，然后取每层末尾元素

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
    public List<Integer> rightSideView(TreeNode root) {
        List<List<Integer>> orderList = levelOrder(root);
        List<Integer> result = new ArrayList<>();

        for (List<Integer> integers : orderList) {
            result.add(integers.get(integers.size() - 1));
        }

        return result;
    }

    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        level(list, 0, root);
        return list;
    }

    public void level(List<List<Integer>> list, Integer level, TreeNode node) {
        if (node == null) {
            return;
        }
        if (list.size() <= level) {
            List<Integer> l = new ArrayList<>();
            l.add(node.val);
            list.add(l);
        } else {
            list.get(level).add(node.val);
        }
        level++;
        level(list, level, node.left);
        level(list, level, node.right);
    }
}
```