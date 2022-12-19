### 解题思路
二叉搜索树的中序遍历，是一个严格的单调递增数列，所以，我们只需要进行中序遍历，就能找到第k小的元素。

每次遍历将i+1，直到i==k时，返回节点的值即可。

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
    public int kthSmallest(TreeNode root, int k) {
        int i = 0;
        TreeNode node = root;
        Stack<TreeNode> stack = new Stack<>();
        while (node != null || !stack.isEmpty()) {
            if (node != null){
                stack.push(node);
                node = node.left;
            }else {
                node = stack.pop();
                i++;
                if (i == k) {
                    return node.val;
                }
                node = node.right;
            }
        }
        return 0;
    }
}
```