上代码吧
```
class Solution {
    public int rob(TreeNode root) {
        
        if (root == null)
            return 0;
        
        //保存入参的根节点，返回值时使用
        TreeNode oldRoot = root;
        
        //后序遍历的栈和标记位集合
        Stack<TreeNode> stack = new Stack<>();
        Set<TreeNode> flags = new HashSet<>();
        //存放包含根节点node的树的的最大抢劫值
        Map<TreeNode, Integer> includeMap = new HashMap<>();
        //存放不包含根节点node的树的最大抢劫值
        Map<TreeNode, Integer> excludeMap = new HashMap<>();
        
        while (root != null) {
            stack.push(root);
            root = root.left;
        }
        
        while (!stack.isEmpty()) {
            
            TreeNode node = stack.peek();
            
            if (node.right == null 
                || flags.contains(node)) {
                stack.pop();
                
                //包含根节点的最大抢劫值：根+不含左子节点的最大+不含右子节点的最大
                int includeMax = node.val 
                    + (node.left == null ? 0 : excludeMap.get(node.left))
                    + (node.right == null ? 0 : excludeMap.get(node.right));
                //不包含根节点的最大抢劫值：max(包含左子的最大, 不含左子的最大) + max(包含右子的最大, 不含右子的最大)
                int excludeMax =Math.max(
                    (node.left == null ? 0 : includeMap.get(node.left)),
                    (node.left == null ? 0 : excludeMap.get(node.left)))
                    + Math.max(
                    (node.right == null ? 0 : includeMap.get(node.right)),
                    (node.right == null ? 0 : excludeMap.get(node.right)));
                
                includeMap.put(node, includeMax);
                excludeMap.put(node, excludeMax);
                
                continue;
            }
            
            TreeNode right = node.right;
            
            flags.add(node);
            
            while (right != null) {
                stack.push(right);
                right = right.left;
            } 
            a
        }
        
        return Math.max(includeMap.get(oldRoot), excludeMap.get(oldRoot));
    }
}
```
