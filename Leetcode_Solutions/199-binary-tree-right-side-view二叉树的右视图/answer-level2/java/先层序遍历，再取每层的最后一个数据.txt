### 解题思路
先层序遍历（可参考102题，递归和迭代都可以），再取每层的最后一个数据

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
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        List<List<Integer>> lists = new ArrayList<>();
        loopFloor(lists, root, 0);
        for (int i = 0;i < lists.size();i++) {  //取每层的最后一个数据放入result中
            List<Integer> temp = lists.get(i);
            result.add(temp.get(temp.size() - 1));
        }
        return result;
    }

    /**
     * 递归执行层序遍历
     */
    private void loopFloor(List<List<Integer>> lists, TreeNode root, int floor) {
        if (root == null) {
            return;
        }
        if (lists.size() == floor) {
            lists.add(new ArrayList<>());
        }
        lists.get(floor).add(root.val);
        loopFloor(lists, root.left, ++floor);
        loopFloor(lists, root.right, floor);
    }
}
```