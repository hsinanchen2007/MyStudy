执行用时：2 ms，仅次于0ms的最优提交，但如果你看过0ms解法，就知道这个实际已经是最优解了。
（0ms解法摘录在最后，相当鬼才）
```java
public class Codec {
    public String serialize(TreeNode root) {
        if (root == null) return null;
        StringBuilder sb = new StringBuilder();
        serializeByDLR(root, sb);
        return sb.toString();
    }

    void serializeByDLR(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append(',');
            return;
        }
        sb.append(root.val).append(',');
        serializeByDLR(root.left, sb);
        serializeByDLR(root.right, sb);
    }

    public TreeNode deserialize(String data) {
        if (data == null || data.length() == 0) return null;
        return deserializeByDLR(data, new int[1]);
    }

    TreeNode deserializeByDLR(String data, int[] i) {
        if (i[0] >= data.length()) return null;
        char ch = data.charAt(i[0]);
        if (ch == ',') {
            i[0]++;
            return null;
        }

        int val = 0;
        boolean negative = ch == '-';
        if (negative) i[0]++;
        while (i[0] < data.length() && (ch = data.charAt(i[0]++)) != ',') {
            val *= 10;
            val += Character.digit(ch, 10);
        }
        val = negative ? -val : val;

        TreeNode node = new TreeNode(val);
        node.left = deserializeByDLR(data, i);
        node.right = deserializeByDLR(data, i);
        return node;
    }
}
```

补一个广度优先算法，利用层序遍历实现：
```java
public class Codec {
    public String serialize(TreeNode root) {
        if (root == null) return null;
        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node != null) {
                queue.offer(node.left);
                queue.offer(node.right);
                sb.append(node.val);
            }
            sb.append(',');
        }
        return sb.toString();
    }

    public TreeNode deserialize(String data) {
        if (data == null || data.length() == 0) return null;
        int[] i = new int[1];
        TreeNode root = new TreeNode(parseInt(data, i));
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty() && i[0] < data.length()) {
            TreeNode node = queue.poll();
            if (node != null) {
                if (isNotNull(data, i)) {
                    node.left = new TreeNode(parseInt(data, i));
                    queue.offer(node.left);
                }
                if (isNotNull(data, i)) {
                    node.right = new TreeNode(parseInt(data, i));
                    queue.offer(node.right);
                }
            }
        }
        return root;
    }

    private boolean isNotNull(String data, int[] i) {
        if (i[0] < data.length() && data.charAt(i[0]) != ',') return true;
        i[0]++;
        return false;
    }

    private int parseInt(String data, int[] i) {
        int val = 0;
        char ch = data.charAt(i[0]);
        boolean negative = ch == '-';
        if (negative) i[0]++;
        while (i[0] < data.length() && (ch = data.charAt(i[0]++)) != ',') {
            val *= 10;
            val += Character.digit(ch, 10);
        }
        val = negative ? -val : val;
        return val;
    }
}
```



0ms解法，优秀到没朋友！
```java
public class Codec {
    private TreeNode root;

    public String serialize(TreeNode root) {
        this.root = root;
        return null;
    }

    public TreeNode deserialize(String data) {
        return root;
    }
}
```

