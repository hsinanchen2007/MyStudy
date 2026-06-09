```
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        int depth = 0;
        List<Integer> result = new ArrayList<>();
        ArrayDeque<TreeNode> stack = this.findParent(root, target);
        Set<TreeNode> parent = new HashSet<>(stack);
        TreeNode node = stack.pop();
        this.findNode(node, target, depth++, K, result, parent);                // 搜索目标节点本身及其子节点
        while(!stack.isEmpty() && depth <= K) {
            this.findNode(stack.pop(), target, depth++, K, result, parent);     // 搜索目标节点的父节点
        }
        return result;
    }

    /**
     * 根据二叉树后序遍历的性质，搜索到当前节点时，栈中的所有节点皆为其父节点
     * @param root      根节点
     * @param target    目标节点
     * @return
     */
    public ArrayDeque<TreeNode> findParent(TreeNode root, TreeNode target) {
        if(root == null) {
            return null;
        }
        TreeNode pre =  null;
        ArrayDeque<TreeNode> stack = new ArrayDeque<>();            // 栈，保存目标节点及其父节点
        while(!stack.isEmpty() || root != null) {
            while(root != null) {
                stack.push(root);
                root = root.left;
            }
            root = stack.peek();
            if(root.right != null && root.right != pre) {
                root = root.right;
                stack.push(root);
                root = root.left;
            } else {
                if(stack.peek().val == target.val) {
                    return stack;                                   // 找到目标直接返回
                }
                pre = stack.pop();
                root = null;
            }
        }
        return null;
    }

    /**
     * 搜索当前节点及其子节点中距离目标节点的距离为 K 的所有节点
     * @param node      当前搜索的节点
     * @param target    目标节点
     * @param depth     当前距离
     * @param K         目标距离
     * @param result    保存结果的集合
     * @param parent    目标节点的所有父节点集合
     */
    public void findNode(TreeNode node, TreeNode target, int depth, int K, List<Integer> result, Set<TreeNode> parent) {
        if(node == null) {
            return;
        }
        if(depth == K) {
            result.add(node.val);
            return;
        }
        if(!parent.contains(node.left)) {                                               // 子节点在父路径里不再搜索
            findNode(node.left, target, depth + 1, K, result, parent);
        }
        if(!parent.contains(node.right)) {                                              // 子节点在父路径里不再搜索
            findNode(node.right, target, depth + 1, K, result, parent);
        }
    }
}
```
