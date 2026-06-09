```java
// Encodes a tree to a single string.
// 这里将原二叉树转化为层次遍历，最后会多出一个“，”但是没什么关系。
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node == null) {
                sb.append("#,");
            } else {
                sb.append(node.val).append(",");
                queue.offer(node.left);

                queue.offer(node.right);

            }
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] strings = data.split(",");//这个可能会比较耗时，如果追求时间可以自己实现，比如“13212，4564，83，#，5”这样，自己扫描得到整数
                                            //但是我感觉这样已经偏离题意了。
        if (strings.length == 1 && strings[0].equals("#")){
            return null;
        }
        // 利用一个队列保存下一层的结点
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode head = new TreeNode(Integer.parseInt(strings[0]));
        queue.offer(head);
        int index = 1;
        while (index < strings.length) {
            TreeNode node = queue.poll();
            if (node != null) {
                TreeNode left = strings[index].equals("#") ? null : new TreeNode(Integer.parseInt(strings[index]));
                index++;
                queue.offer(left);
                node.left = left;

                TreeNode right = strings[index].equals("#") ? null : new TreeNode(Integer.parseInt(strings[index]));
                index++;
                queue.offer(right);
                node.right = right;
            }
        }
        return head;
    }
```
