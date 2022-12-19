```
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null) {
            return "[]";
        }
        Deque<TreeNode> deque = new LinkedList<>();
        deque.add(root);
        StringBuilder sb = new StringBuilder();
        sb.append("[");

        while(!deque.isEmpty()) {
            TreeNode t = deque.remove();
            if(t == null) {
                sb.append("null,");
            } else {
                sb.append(t.val + ",");
                deque.add(t.left);
                deque.add(t.right);
            }
        }

        sb.deleteCharAt(sb.length() - 1);
        sb.append("]");
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data.equals("[]")) {
            return null;
        }
        data = data.substring(1, data.length() - 1);
        String[] s = data.split(",");
        int cnt = 1;
        Deque<TreeNode> deque = new LinkedList<>();
        TreeNode ref = new TreeNode(Integer.parseInt(s[0]));
        deque.add(ref);
        while(!deque.isEmpty()) {
            TreeNode t = deque.remove();
            if(!s[cnt].equals("null")) {
                t.left = new TreeNode(Integer.parseInt(s[cnt]));
                deque.add(t.left);
            }
            cnt++;
            if(!s[cnt].equals("null")) {
                t.right = new TreeNode(Integer.parseInt(s[cnt]));
                deque.add(t.right);
            }
            cnt++;
        }
        return ref;
    }
}

```
