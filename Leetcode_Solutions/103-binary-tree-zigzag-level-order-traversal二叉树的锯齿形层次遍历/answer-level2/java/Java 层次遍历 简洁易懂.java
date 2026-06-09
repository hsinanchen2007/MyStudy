```
public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    if (root == null)
        return new ArrayList<>();

    List<Integer> nodes = new ArrayList<>();
    List<Integer> nodesTemp;
    List<TreeNode> tns = new ArrayList<>();
    List<TreeNode> tnsTemp;
    List<List<Integer>> nodeList = new ArrayList<>();
    nodes.add(root.val);
    tns.add(root);
    nodeList.add(nodes);
    // 初始从右开始
    boolean left = false;
    while (true) {
        // 注意要重新 new 对象  下同
        tnsTemp = new ArrayList<>();
        nodesTemp = new ArrayList<>();
        if (!left) {// 从右边开始
            for (int i = tns.size() - 1; i >= 0; i--) {
                TreeNode node = tns.get(i);
                if (node.right != null) {
                    tnsTemp.add(node.right);
                    nodesTemp.add(node.right.val);
                }
                if (node.left != null) {
                    tnsTemp.add(node.left);
                    nodesTemp.add(node.left.val);
                }
            }
            left = true;
        } else {
            // 从左边开始
            for (int i = tns.size() - 1; i >= 0; i--) {
                TreeNode node = tns.get(i);
                if (node.left != null) {
                    tnsTemp.add(node.left);
                    nodesTemp.add(node.left.val);
                }
                if (node.right != null) {
                    tnsTemp.add(node.right);
                    nodesTemp.add(node.right.val);
                }
            }
            left = false;
        }
        tns = new ArrayList<>();
        nodes = new ArrayList<>();
        tns.addAll(tnsTemp);
        nodes.addAll(nodesTemp);
        if (nodes.size() == 0)
            break;
        nodeList.add(nodes);
    }
    return nodeList;
}

```