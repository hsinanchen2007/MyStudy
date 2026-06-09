### 解题思路
使用递归遍历树，思路比较简单。

**递归函数要做的事**：
  获取左右子树的深度，判断左右子树之和是否大于当前直径最大值，大于就替换，最后返回该节点的深度；

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
    int max_length;  //  保存最大直径
    public int diameterOfBinaryTree(TreeNode root) {
        path_length(root);
        return max_length;
    }

    public int path_length(TreeNode root) {
        if(root==null)
            return 0;
        //  获取左右子树的深度
        int left = path_length(root.left);
        int right = path_length(root.right);
        //  比较大小，满足条件就替换
        if(max_length-left<=right) {
            max_length=left+right;
        }
        //  返回深度
        return (left>right?left:right)+1;
    }
}
```