### 解题思路
分别得到两个叶子节点的集合
深度优先去遍历节点

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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> list1 = getLeaf(root1);
        List<Integer> list2 = getLeaf(root2);
        if (list1.size() != list2.size()) {
            return false;
        }
        for (int i = 0; i < list1.size(); i++) {
            if (!list1.get(i).equals(list2.get(i))) {
                return false;
            }
        }
        return true;
    }

    private List<Integer> getLeaf(TreeNode node) {
        List<Integer> list = new ArrayList<>();
        doAddLeafToList(list, node);
        return list;
    }

    private void doAddLeafToList(List<Integer> list, TreeNode node) {
        if (node != null) {
            if (node.left == null && node.right == null) {
                list.add(node.val);
            }
            if (node.left != null) {
                doAddLeafToList(list, node.left);
            }
            if (node.right != null) {
                doAddLeafToList(list, node.right);
            }
        }
    }
}
```