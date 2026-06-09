### 解题思路
首先把to_delete变成set，此处不多说；
节点进入结果当中，有2个条件：
* 不被删除
* 父节点不存在
因此在遍历过程中，将parentExists标志传递给子节点，子递归就可以选择是否加入到结果。
另外，如果子节点被删除，父节点的left、right字段需要更新。

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
    Set<Integer> toDelete;
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        toDelete = Arrays.stream(to_delete).boxed().collect(Collectors.toSet());
        List<TreeNode> ans = new ArrayList<>();
        helper(root, ans, false);
        return ans;
    }

    boolean helper(TreeNode root, List<TreeNode> ans, boolean parentExists) {
        boolean del = false;
        if (root == null) {
            return del;
        }
        del = toDelete.contains(root.val);
        if (helper(root.left, ans, !del)) {
            root.left = null;
        }
        if (helper(root.right, ans, !del)) {
            root.right = null;
        }
        if (!del && !parentExists) {
            ans.add(root);
        }
        return del;
    }
}
```