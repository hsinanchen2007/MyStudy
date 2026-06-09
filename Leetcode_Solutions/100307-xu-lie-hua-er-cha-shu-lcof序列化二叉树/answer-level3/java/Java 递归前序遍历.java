### 解题思路
前序遍历处理，注意反序列化要有一个字段记录下标位置。

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
public class Codec {

    int index = 0;      //全局变量，用于记录反序列化时候，处理到了第几位字符。
    StringBuffer sb = new StringBuffer();
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
       

       dfs_s(root);
       sb.deleteCharAt(sb.length() - 1);
       return sb.length() == 0 ? "" : sb.toString();
    }

    private void dfs_s(TreeNode root) {
        if (root == null) sb.append("null,");
        else {
            sb.append(root.val + ",");
            dfs_s(root.left);
            dfs_s(root.right);
        }
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        return dfs_d(data);
    }

    private TreeNode dfs_d(String data) {
        if (index >= data.length()) return null;

        StringBuffer d = new StringBuffer();
        while (index < data.length() && data.charAt(index) != ',') {    // 只要不是逗号，就说明该内容是一个整体，那么就都append进来。
            d.append(data.charAt(index));
            index++;
        }

        index++;                    //当前index是逗号，所以要将index + 1右移。（下次递归进while循环就能继续append新内容了）

        TreeNode node;
        if (d.toString().equals("null")) {           // 处理该片段内容（StringBuffer）
            node = null;
        } else {
            node = new TreeNode(Integer.parseInt(d.toString()));
            node.left = dfs_d(data);      
            node.right = dfs_d(data);
        }

        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```

执行用时 :16 ms, 在所有 Java 提交中击败了79.70% 的用户
内存消耗 :42.2 MB, 在所有 Java 提交中击败了100.00%的用户