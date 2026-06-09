### 解题思路
BST树中序遍历（inorder traversal）, 把每个结点的值放入待验证的List。
如果是有效的BST树，那么该List是无重复元素且升序的。


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

    private void inorder(TreeNode node, List<Integer> list) {
        if (node != null) {
            inorder(node.left, list);
            list.add(node.val);
            inorder(node.right, list);
        }
    }

    private boolean isSorted(List<Integer> list) {
        for (int i = 0; i < list.size() - 1; i++) {
            if (list.get(i) >= list.get(i + 1))
                return false;
        }
        return true;
    }

    // 又一个无赖解法 .... .... .... ....
    public boolean isValidBST(TreeNode root) {

        if (root == null) return true;

        List<Integer> list = new ArrayList<>();
        inorder(root, list); // BST经过中序遍历 List中的元素是升序且不重复的.

        return isSorted(list);
    }
}
```