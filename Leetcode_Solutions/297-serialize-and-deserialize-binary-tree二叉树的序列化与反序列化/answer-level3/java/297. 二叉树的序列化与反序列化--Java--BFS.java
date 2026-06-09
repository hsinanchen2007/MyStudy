[Leetcode-Java(更多题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_297_Codec.java)

```java
    // Encodes a tree to a single string.

    /**
     * 按层次遍历，序列化格式：1 2 3 null null 4 5 null null null null
     * 借助队列实现树的BFS
     * @param root
     * @return
     */
    public String serialize(TreeNode root) {
        StringBuilder builder = new StringBuilder();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode pop = queue.poll();
            builder.append(pop != null ? pop.val : null).append(" ");
            if (pop != null) {
                queue.add(pop.left);
                queue.add(pop.right);
            }
        }

        return builder.toString();

    }

    // Decodes your encoded data to tree.

    /**
     * "1 2 3 null null 4 5 null null null null"遍历数组，使用BFS反序列化生成Tree
     * @param data
     * @return
     */
    public TreeNode deserialize(String data) {
        String[] split = data.split(" ");
        if (split.length == 0) return null;
        String top = split[0];
        if (top.equals("null")) {
            return null;
        }
        TreeNode root = new TreeNode(toInt(top));
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int index = 1;
        while (!queue.isEmpty() && index < split.length) {
            TreeNode poll = queue.poll();
            String left = split[index++];
            String right = split[index++];
            if (!left.equals("null")) {
                TreeNode leftNode = new TreeNode(toInt(left));
                poll.left = leftNode;
                queue.add(leftNode);
            }
            if (!right.equals("null")) {
                TreeNode rightNode = new TreeNode(toInt(right));
                poll.right = rightNode;
                queue.add(rightNode);
            }
        }

        return root;
    }

    private int toInt(String str) {
        return Integer.parseInt(str);
    }

```