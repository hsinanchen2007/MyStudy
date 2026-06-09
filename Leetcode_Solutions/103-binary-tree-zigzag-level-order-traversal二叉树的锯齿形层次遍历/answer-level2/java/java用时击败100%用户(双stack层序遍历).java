public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    List<List<Integer>> levels = new ArrayList<>();
    if (root == null){
        return levels;
    }
    
    Stack<TreeNode> even = new Stack<>();//偶数层
    Stack<TreeNode> odd = new Stack<>();//奇数层
    even.push(root);
    int level = 0;
    while (!even.isEmpty() || !odd.isEmpty()){
        if (!even.isEmpty()) {
            levels.add(new ArrayList<>());
            while (!even.isEmpty()) {
                TreeNode node = even.pop();
                levels.get(level).add(node.val);
                if (node.left != null){
                    odd.push(node.left);
                }
                if (node.right != null) {
                    odd.push(node.right);
                }
            }
            level++;
        }
        
        if (!odd.isEmpty()) {
            levels.add(new ArrayList<>());
            while (!odd.isEmpty()) {
                TreeNode node = odd.pop();
                levels.get(level).add(node.val);
                if (node.right != null) {
                    even.push(node.right);
                }
                if (node.left != null) {
                    even.push(node.left);
                }
            }
            level++;
        }
        
    }
    return levels;
}