### 解题思路
数组里的值转换为二叉树
![image.png](https://pic.leetcode-cn.com/ff86628cadf5615cd423c49e594de3b56a7e5e36a7f741423b1126a528ab688b-image.png)


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

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null){
            return "[]";
        }
        StringBuilder sb = new StringBuilder("[");
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()){
            TreeNode node = queue.poll();
            if (node != null){
                sb.append(node.val + ",");
                queue.offer(node.left);
                queue.offer(node.right);
            } else {
                sb.append("null,");
            }
        }
        sb.deleteCharAt(sb.length() - 1);
        while (sb.length() > 5 && sb.lastIndexOf(",null") == sb.length() - 5){
            sb.delete(sb.length() - 5, sb.length());
        }
        return sb.append("]").toString();

    }

    public static TreeNode deserialize(String data) {
        if ("[]".equals(data)){
            return null;
        }
        data = data.substring(1, data.length() - 1);
        String[] datas = data.split(",");
        int len = datas.length;
        if (len == 0){
            return null;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode treeNode = new TreeNode(Integer.valueOf(datas[0]));
        queue.offer(treeNode);
        for (int i = 0; i < len / 2; i++) {
            TreeNode root = queue.poll();
            if ((i << 1) + 1 >= len || "null".equals(datas[(i << 1) + 1])){
                root.left = null;
            } else {
                root.left = new TreeNode(Integer.valueOf(datas[(i << 1) + 1]));
                queue.offer(root.left);
            }
            if ((i << 1) + 2 >= len || "null".equals(datas[(i << 1) + 2])){
                root.right = null;
            } else{
                root.right = new TreeNode(Integer.valueOf(datas[(i << 1) + 2]));
                queue.offer(root.right);
            }
        }
        return treeNode;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```