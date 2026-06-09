```
/** 和104题基本类似 只是加了个特殊情况的判断 */
class Solution {
	public int minDepth(TreeNode root) {
        if (root == null)
        	return 0;
        if (root.left == null && root.right != null)
        	return minDepth(root.right) + 1;
        if (root.right == null && root.left != null)
        	return minDepth(root.left) + 1;
        int leftHeight = minDepth(root.left);
        int rightHeight = minDepth(root.right);
        return Math.min(leftHeight, rightHeight) + 1;      
    }	
}

/** bfs 还是104提的套路 感觉bfs比递归更直接一些 */
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null)
            return 0;
        int depth = 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            depth += 1;
            int size= queue.size();
            for (int i = 0; i < size; i ++) {
                TreeNode node = queue.poll();
                if (node.left == null && node.right == null) 
                    return depth;
                if (node.left != null) 
                    queue.add(node.left);
                if (node.right != null)
                    queue.add(node.right);
            }
        }
        return depth;// 实际没用
    }
}

/** dfs 我这段代码效率极低 因为在找到了叶子节点之后无法停止当前分支 假设左节点已然为叶子节点 但是右节点还有子节点 那么还是会继需*/
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null)
            return  0;
        int res = Integer.MAX_VALUE;
        Stack<TreeNode> stack = new Stack<>();
        Stack<Integer> val = new Stack<>();
        stack.push(root);
        val.push(1);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            int tmp = val.pop();
            if (node.left == null && node.right == null) 
                res = Math.min(tmp, res);
            if (node.right != null) {
                stack.push(node.right);
                val.push(tmp + 1);
            }
            if (node.left != null) {
                stack.push(node.left);
                val.push(tmp + 1);
            }
        }
        return res; 
    }
}