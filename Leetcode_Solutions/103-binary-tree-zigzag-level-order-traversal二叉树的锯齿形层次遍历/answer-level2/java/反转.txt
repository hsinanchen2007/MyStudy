### 解题思路
直接对二叉树进行层次遍历后，对奇数层进行反转即可得到结果。

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        levelOrder(root, result, 0);
        for(int i = 1; i < result.size(); i += 2) {
            Collections.reverse(result.get(i));
        }
        return result;
    }

    public void levelOrder(TreeNode root, List<List<Integer>> list, int currLevel) {
        if(root == null) {
            return;
        }
        if(list.size() == currLevel) {
            list.add(new ArrayList<Integer>());
        }
        list.get(currLevel).add(root.val);
        levelOrder(root.left, list, currLevel + 1);
        levelOrder(root.right, list, currLevel + 1);
        return;
    }
}
```