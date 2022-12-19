### 解题思路

以StringBuilder存储字符串的值，通过递归遍历将各个节点的值拼接到字符串中。
在叶子节点处将已经拼装好的路径字符串值添加到 list 中

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
    List<String> result = new ArrayList();
    public List<String> binaryTreePaths(TreeNode root) {
        if(root == null){
            return result;
        } else if (root.left == null && root.right == null){
            result.add(String.valueOf(root.val));
            return result;
        }

        binaryTreePaths(root.left,new StringBuilder(String.valueOf(root.val)));
        binaryTreePaths(root.right,new StringBuilder(String.valueOf(root.val)));
        return result;
    }

    public void binaryTreePaths(TreeNode root,StringBuilder parentPath) {

        if(root == null){
            return;
        }
        StringBuilder sb = new StringBuilder(parentPath.toString());
        sb.append("->").append(String.valueOf(root.val));
        //在叶子节点才将节点路径添加进 list 中
        if(root.left == null && root.right == null){
            result.add(sb.toString());
            return;
        }
        
        if (root.left != null){
            binaryTreePaths(root.left,sb);
        }

        if (root.right != null){
            binaryTreePaths(root.right,sb);
        }
    }
}
```