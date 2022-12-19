### 解题思路
此处撰写解题思路

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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();
        helper(root, res, new StringBuilder());
        return res;
    }

    public void helper(TreeNode root, List<String> res, StringBuilder sb) {
        //初始root为null
        if (root == null)   return;
        //只要是节点，都要添加值
        String val = String.valueOf(root.val);
        int LenofVal = val.length();//值的长度
        sb.append(val);
        //若为叶子节点，添加结果，删除值，并返回
        if (root.left == null && root.right == null) {
            res.add(sb.toString());
            //删除值
            for (int i = 0; i < LenofVal; i++) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return;
        }
        //左子女存在
        if (root.left != null) {
            sb.append("->");
            helper(root.left, res, sb);
            sb.deleteCharAt(sb.length() - 1);//删除"-"
            sb.deleteCharAt(sb.length() - 1);//删除">"
        }
        //右子女存在
        if (root.right != null) {
            sb.append("->");
            helper(root.right, res, sb);
            sb.deleteCharAt(sb.length() - 1);
            sb.deleteCharAt(sb.length() - 1);
        }
        //中间节点处理完子女，来到这里
        //删除中间节点的值
        for (int i = 0; i < LenofVal; i++) {
            sb.deleteCharAt(sb.length() - 1);
        }
        return;
    }
}
```