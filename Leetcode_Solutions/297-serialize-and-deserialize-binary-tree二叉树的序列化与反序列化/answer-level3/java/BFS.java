### 解题思路
BFS

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
        StringBuilder sb = new StringBuilder();
        if (root == null) {
            return sb.append("#").append(",").toString();
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        sb.append(root.val).append(",");

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                root = queue.poll();

                if (root.left != null) {
                    queue.add(root.left);
                    sb.append(root.left.val).append(",");
                } else {
                    sb.append("#").append(",");
                }

                if (root.right != null) {
                    queue.add(root.right);
                    sb.append(root.right.val).append(",");
                } else {
                    sb.append("#").append(",");
                }
            }
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] strings = data.split(",");
        int index = 0;
        TreeNode root = "#".equals(strings[index]) ? null : new TreeNode(Integer.parseInt(strings[index]));
        index++;

        if (root == null) {
            return null;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode poll = queue.poll();
                poll.left = "#".equals(strings[index]) ? null : new TreeNode(Integer.parseInt(strings[index]));
                index++;
                poll.right = "#".equals(strings[index]) ? null : new TreeNode(Integer.parseInt(strings[index]));
                index++;

                if(poll.left != null) {
                    queue.add(poll.left);
                }

                if(poll.right != null) {
                    queue.add(poll.right);
                }

            }

        }

        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```