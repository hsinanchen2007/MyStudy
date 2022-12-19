### 解题思路
本题使用递归求解二叉树所有的路径，将路径下的元素放在 `ans` 结果集中

- 首先**判空**，如果**只有根结点**就直接放入 `ans` 并返回即可

- 其他结点只要有左孩子或右孩子或者左右孩子都有，就递归进行处理

- 创建该结点下的**左子树路径**和**右子树路径**，循环遍历路径下的结点元素依次用 `->` 链接**该结点和他的孩子**，并放入结果集中继续让其孩子递归遍历，所有结点遍历完就返回该结果集中的内容。

### 代码

```java []
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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        // 如果是叶子结点就加入到 ans 结果集中
        if (root.left == null && root.right == null) {
            ans.add(Integer.toString(root.val));
            return ans;
        }
        // 创建左子树结点集合
        List<String> leftPaths = binaryTreePaths(root.left);
        for (String s : leftPaths) {
                                                // 先将该结点加入到字符串中
            StringBuilder sb = new StringBuilder(Integer.toString(root.val));
            sb.append("->");
            sb.append(s);
            ans.add(sb.toString());
        }
        // 创建右子树结点集合
        List<String> rightPaths = binaryTreePaths(root.right);
        for (String s : rightPaths) {
            StringBuilder sb = new StringBuilder(Integer.toString(root.val));
            sb.append("->");
            sb.append(s);
            ans.add(sb.toString());
        }
        return ans;
    }
}
```