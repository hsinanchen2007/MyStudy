### 解题思路
递归思路很简单 没啥可说的

### 代码

```java
import java.util.List;
import java.util.ArrayList;
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
    public List<Integer> inorderTraversal(TreeNode root) {
          //返回的列表
          List<Integer> list = new ArrayList<Integer>();

          //递归遍历二叉树
          inorderTree(root, list);

          return list;
    }

    //递归写法 二叉树中序遍历
    private void inorderTree(TreeNode root, List<Integer> list) {
        if (root == null) {
            return;
        }

        //递归左节点
        if (root.left != null) {
            inorderTree(root.left, list);
        }

        //增加中间节点到list
        list.add(root.val);

        //递归右节点
        if (root.right != null) {
            inorderTree(root.right, list);
        }
    }
}
```