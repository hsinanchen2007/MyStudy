### 解题思路
随便写完发现数据还挺好（。
就是交替用了两个queue和list 感觉比计数直观一点2333

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return new ArrayList<>();
        Queue<TreeNode> q1 = new LinkedList<>();
        Queue<TreeNode> q2 = new LinkedList<>();
        q1.add(root);
        List<List<Integer>> result = new ArrayList<>();
        while (!(q1.isEmpty() && q2.isEmpty())) {
            List<Integer> l1 = new ArrayList<>();
            while (!q1.isEmpty()) {
                TreeNode n = q1.remove();
                l1.add(n.val);
                if (n.left != null)q2.add(n.left);
                if (n.right != null)q2.add(n.right);
            }
            if (l1.size() != 0) result.add(l1);

            List<Integer> l2 = new ArrayList<>();
            while (!q2.isEmpty()) {
                TreeNode n = q2.remove();
                l2.add(n.val);
                if (n.left != null)q1.add(n.left);
                if (n.right != null)q1.add(n.right);
            }
            if (l2.size() != 0) result.add(l2);
        }

        return result;
    }
}
```