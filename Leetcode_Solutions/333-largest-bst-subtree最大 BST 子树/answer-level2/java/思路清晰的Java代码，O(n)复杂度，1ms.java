### 解题思路

一次遍历，visit方法返回从该节点以下找到的BST信息，包括根节点、最大值、最小值、尺寸。为了方便返回多个值，也方便代码阅读，封装成了一个Result类。

有几种可能：
- 左右子树均为BST，且满足 `左子树max < node < 右子树min`，则当前树也是BST
- 左右子树中都搜索到了BST，则返回size更大的
- 左右子树之一搜索到了BST，则直接返回
- 左右子树都没搜索到BST，则返回null


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

    class Result {
        TreeNode node; // BST根节点
        int size; // BST的size
        int max; // BST的最大值
        int min; // BST的最小值
    }

    public int largestBSTSubtree(TreeNode root) {
        Result r = visit(root);
        return r == null ? 0 : r.size;
    }

    public Result visit(TreeNode node) {
        if (node == null) return null;

        Result l = null, r = null;
        if (node.left != null) l = visit(node.left);
        if (node.right != null) r = visit(node.right);

        // 当前树为BST
        boolean lValid = (l == null || (l.node == node.left && l.max < node.val));
        boolean rValid = (r == null || (r.node == node.right && r.min > node.val));
        if (lValid && rValid) {
            Result result = new Result();
            result.node = node;
            result.max = r == null ? node.val : r.max;
            result.min = l == null ? node.val : l.min;
            result.size = (l == null ? 0 : l.size) + (r == null ? 0 : r.size) + 1;
            return result;
        }

        // 左右子树中找到了BST
        if (l != null && r != null) {
            return l.size > r.size ? l : r;
        }
        if (l != null) return l;
        if (r != null) return r;

        return null;
    }
}
```

![image.png](https://pic.leetcode-cn.com/7185bb87e4bbff9f16a6f79b3efa028a4a4c9af7adcbf1316969e1e51881ca1a-image.png)
