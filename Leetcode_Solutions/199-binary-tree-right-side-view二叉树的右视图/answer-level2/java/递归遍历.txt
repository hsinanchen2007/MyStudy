### 解题思路
以节点-右子树-左子树顺序遍历
如果节点深度等于列表长度，表明该深度的节点是第一次出现，故将其加入列表。

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
        List<Integer> view = new ArrayList<Integer>();
        helper(root, view, 0);
        return view;
    }

    public void helper(TreeNode root, List<Integer> list, int currLevel) {
        if(root == null) {
            return;
        }
        if(list.size() == currLevel) {
            list.add(root.val);
        }
        helper(root.right, list, currLevel + 1);
        helper(root.left, list, currLevel + 1);
        return;
    }
}
```