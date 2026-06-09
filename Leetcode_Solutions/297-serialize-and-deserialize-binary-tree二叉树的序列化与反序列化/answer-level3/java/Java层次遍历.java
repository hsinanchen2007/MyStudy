友情提示：字符串比较记得用equals
```

public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        LinkedList<TreeNode> list = new LinkedList<>();
        list.add(root);
        while (!list.isEmpty()) {
            TreeNode temp = list.remove();
            if (temp == null) {
                sb.append(",#");
            } else {
                sb.append(",").append(String.valueOf(temp.val));
                list.add(temp.left);
                list.add(temp.right);
            }
        }
        sb.deleteCharAt(0);
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || data.length() < 3) {
            return null;
        }
        String[] strArray = data.split(",");
        TreeNode root = new TreeNode(Integer.valueOf(strArray[0]));
        LinkedList<TreeNode> list = new LinkedList<>();
        list.add(root);
        int index = 1;
        while (!list.isEmpty()) {
            TreeNode temp = list.remove();
            if (strArray[index].equals("#")) {
                temp.left = null;
            } else {
                temp.left = new TreeNode(Integer.valueOf(strArray[index]));
                list.add(temp.left);
            }
            index++;
            if (strArray[index].equals("#")) {
                temp.right = null;
            } else {
                temp.right = new TreeNode(Integer.valueOf(strArray[index]));
                list.add(temp.right);
            }
            index++;
        }

        return root;
    }
}

```
