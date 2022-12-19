使用迭代，用栈来存储元素
    public List<Integer> inorderTraversal(TreeNode root) {
        LinkedList<TreeNode> treeNodes = new LinkedList<>();
        treeNodes.push(root);
        while (root != null && root.left != null) {
            treeNodes.push(root.left);
            root = root.left;
        }
        List<Integer> list = new ArrayList<>();
        while (!treeNodes.isEmpty()) {
            TreeNode treeNode = treeNodes.pop();
            if(treeNode == null){
                break;
            }
            list.add(treeNode.val);
            if (treeNode.right != null) {
                treeNodes.push(treeNode.right);
                TreeNode t = treeNode.right;
                while (t.left != null) {
                    treeNodes.push(t.left);
                    t = t.left;
                }
            }
        }
        return list;
    }