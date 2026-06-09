也算是通过这道题总结了一下这些解法 一大波代码即将进入战场~
```
/** 递归 和官方题解的一样 可以跳过 */
class Solution {
	private class TreeNode{
		int val;
		TreeNode left;
		TreeNode right;
		
		public TreeNode(int v) {
			val = v;
		}
	}
	
	public boolean isSymmetric(TreeNode root) {
		return isSymmetric(root, root);
	}
	
	public boolean isSymmetric(TreeNode p, TreeNode q) {
		if(p == null && q == null)
			return true;
		if(p == null || q == null)
			return false;
		return (p.val == q.val) && isSymmetric(p.left, q.right) && isSymmetric(p.right, q.left);
	}
}

/** bfs 我选择只用一个队列 用两个队列我也试了一下 效率差不多 ）*/
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;
        return help(root.left, root.right);
    }

    private boolean help(TreeNode p, TreeNode q){
        if (p == null && q == null)
            return true;
        if (p == null || q == null)
            return false;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(p);
        queue.add(q);
        while (!queue.isEmpty()) {
            TreeNode nodeP = queue.poll();
            TreeNode nodeQ = queue.poll();
            if (nodeP == null && nodeQ == null)
                continue;
            if (nodeP == null || nodeQ == null)
                return false;
            if (nodeP.val != nodeQ.val)
                return false;
            else {
                queue.add(nodeP.left);
                queue.add(nodeQ.right);
                queue.add(nodeP.right);
                queue.add(nodeQ.left);
            }
        }
        return true;
    }
}

/** dfs 前序遍历 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;
        return help(root.left, root.right);
    }

    private boolean help(TreeNode p, TreeNode q) {
        if (p == null && q == null)
            return true;
        if (p == null || q == null)
            return false;
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        stack1.push(p);
        stack2.push(q);
        while (!stack1.isEmpty() && !stack2.isEmpty()) {
            TreeNode nodeP = stack1.pop();
            TreeNode nodeQ = stack2.pop();
            if (nodeP == null && nodeQ == null)
                continue;
            if (nodeP == null || nodeQ == null)
                return false;
            if (nodeP.val != nodeQ.val)
                return false;
            else {
                stack1.push(nodeP.left);
                stack1.push(nodeP.right);
                stack2.push(nodeQ.right);
                stack2.push(nodeQ.left);
            }
        }
        return true;
    }
}

/** dfs 中序遍历 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;
        return help(root.left, root.right);
    }

    private boolean help(TreeNode p, TreeNode q) {
        if (p == null && q == null)
            return true;
        if (p == null || q == null)
            return false;
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        while (p != null || q != null || !stack1.isEmpty() || !stack2.isEmpty()) {
            if (p != null && q != null) {
                stack1.push(p);
                stack2.push(q);
                p = p.left;
                q = q.right;
            }
            else if (p == null && q == null) {
                p = stack1.pop();
                q = stack2.pop();
                if (p.val != q.val)
                    return false;
                p = p.right;
                q = q.left;
            }
            else
                return false;
        }
        return true;
    }
}

/** dfs后序遍历 感觉这个遍历方法还是有点啰嗦 要是大家有更好的方法可以在评论里留言哈 谢谢~ */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;
        return help(root.left, root.right);
    }

    private boolean help(TreeNode p, TreeNode q) {
        if (p == null && q == null)
            return true;
        if (p == null || q == null)
            return false;
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack1Temp = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        Stack<TreeNode> stack2Temp = new Stack<>();
        while (p != null || q != null || !stack1Temp.isEmpty() || !stack2Temp.isEmpty()) {
            if (p != null && q != null) {
                stack1.push(p);
                stack1Temp.push(p);
                stack2.push(q);
                stack2Temp.push(q);
                p = p.left;
                q = q.right;
            }
            else if (p == null && q == null) {
                p = stack1Temp.pop();
                q = stack2Temp.pop();
                if (p.val != q.val)
                    return false;
                p = p.right;
                q = q.left;
            }
            else 
                return false;
        }

        while (!stack1.isEmpty() || !stack2.isEmpty()) {
            if (stack1.pop().val != stack2.pop().val)
                return false;
        }
        return true;
    }
}