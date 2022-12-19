看了题目的例子， "[1,2,3,null,null,4,5]"明显是广度遍历，就直接按照这个思路去做了。借助了队列来实现，反序列化的时候快被搞死,看了官方答案明显DFS更简单一些。只是官方不断的创建String对象太占空间，如果字符串经常改变的话还是用StringBuilder吧。第一次提交29ms,第二次提交26ms,大家可以试试看。
```
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        StringBuilder sb = new StringBuilder();
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node != null) {
                queue.offer(node.left);
                queue.offer(node.right);
                sb.append(node.val + ",");
            } else {
                sb.append("null,");
            }
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] strs = data.split(",");
        TreeNode root = null;
        if (!"null".equals(strs[0])) {
            root = new TreeNode(Integer.parseInt(strs[0]));
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int i = 1;
        while (!queue.isEmpty() && i + 1 < strs.length) {
            TreeNode node = queue.poll();
            if (node != null) {
                node.left = "null".equals(strs[i]) ? null : new TreeNode(Integer.parseInt(strs[i]));
                node.right = "null".equals(strs[i+1]) ? null : new TreeNode(Integer.parseInt(strs[i+1]));
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
            i += 2;
        }
        return root;
    }
}
```
