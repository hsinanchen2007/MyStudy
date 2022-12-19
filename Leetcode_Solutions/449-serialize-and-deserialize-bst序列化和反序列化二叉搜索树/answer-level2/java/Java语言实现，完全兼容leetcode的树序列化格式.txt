使用层序遍历实现，兼容任意树的序列化，逻辑还算清晰吧。直接看代码

```
public class Codec {
    //
    // 基于BFS实现，完全兼容leetcode的序列化格式，可以针对任意树，不挑！！！
    // 这样就可以在本地方便的直接使用leetcode的输入数据进行debug啦^_^
    //
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        List<String> resList = new ArrayList<>();
        LinkedList<TreeNode> queue = new LinkedList<>();
        if (root != null) {
            queue.add(root);
            resList.add(String.valueOf(root.val));
        }
        TreeNode tmp;
        List<TreeNode> list = new ArrayList<>();
        TreeNode nonNode = new TreeNode(0);
        while (!queue.isEmpty()) {
            list.clear();
            while (!queue.isEmpty()) {
                list.add(queue.pollFirst());
            }
            for (int i = 0; i < list.size(); i++) {
                tmp = list.get(i);
                if (tmp == nonNode) {
                    continue;
                }
                if (tmp.left == null) {
                    resList.add("null");
                    queue.add(nonNode);
                } else {
                    resList.add(String.valueOf(tmp.left.val));
                    queue.add(tmp.left);
                }
                if (tmp.right == null) {
                    resList.add("null");
                    queue.add(nonNode);
                } else {
                    resList.add(String.valueOf(tmp.right.val));
                    queue.add(tmp.right);
                }
            }
        }
        while (resList.size() > 0 && resList.get(resList.size()-1).equals("null")) {
            resList.remove(resList.size()-1);
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < resList.size(); i++) {
            sb.append(resList.get(i));
            if (i != resList.size()-1) {
                sb.append(",");
            }
        }
        sb.append("]");
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        data = data.substring(1);
        data = data.substring(0, data.length()-1);
        String[] nodes = data.split(",");
        if (nodes.length == 0) {
            return null;
        }
        TreeNode root = null, tmp, node;
        TreeNode nonNode = new TreeNode(0);
        String s;
        boolean f;
        List<TreeNode> list = new ArrayList<>();
        LinkedList<TreeNode> queue = new LinkedList<>();
        for (int i = 0; i < nodes.length; i++) {
            if (root == null) {
                s = nodes[i];
                if (s.equals("null") || s.isEmpty()) {
                    break;
                }
                root = new TreeNode(Integer.valueOf(s));
                queue.add(root);
            } else {
                s = nodes[i];
                list.clear();
                while (!queue.isEmpty()) {
                    list.add(queue.pollFirst());
                }
                f = true;
                for (int j = 0; j < list.size(); j++) {
                    tmp = list.get(j);
                    if (tmp == nonNode) {
                        continue;
                    }
                    if (!f) {
                        i++;
                        if (i >= nodes.length) {
                            break;
                        }
                        s = nodes[i];
                    }
                    f = false;
                    if (s.equals("null")) {
                        tmp.left = null;
                        queue.add(nonNode);
                    } else {
                        node = new TreeNode(Integer.valueOf(s));
                        tmp.left = node;
                        queue.add(node);
                    }
                    i++;
                    if (i >= nodes.length) {
                        break;
                    }
                    s = nodes[i];
                    if (s.equals("null")) {
                        tmp.right = null;
                        queue.add(nonNode);
                    } else {
                        node = new TreeNode(Integer.valueOf(s));
                        tmp.right = node;
                        queue.add(node);
                    }
                }
            }
        }
        return root;
    }
}
```
