### 解题思路
使用遍历加map的方式记录节点的深度和位置，通过每层的位置相减的最大值求得最后结果。
![image.png](https://pic.leetcode-cn.com/0d9bf2e440359b48617462e2867747b9e5e3743a8bbf5db448e2ee442d705af1-image.png)


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
    int widthOfBinaryTreeResult = 0;

    public int widthOfBinaryTree(TreeNode root) {
        traverse(root, 1, 0, new HashMap<>());
        return widthOfBinaryTreeResult;
    }

    private void traverse(TreeNode treeNode, int index, int depth, Map<Integer, Integer> map) {
        if (treeNode.left != null) traverse(treeNode.left, index * 2 - 1, depth + 1, map);
        if (map.get(depth) == null) {
            map.put(depth, index);
            widthOfBinaryTreeResult = Math.max(widthOfBinaryTreeResult, 1);
        } else {
            widthOfBinaryTreeResult = Math.max(widthOfBinaryTreeResult, index - map.get(depth) + 1);
        }
        if (treeNode.right != null) traverse(treeNode.right, index * 2, depth + 1, map);
    }
}
```