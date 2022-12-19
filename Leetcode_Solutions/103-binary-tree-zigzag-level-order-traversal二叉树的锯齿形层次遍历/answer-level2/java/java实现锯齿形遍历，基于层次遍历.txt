就是很简单的BFS。很多代码可以抄层次遍历的。
如果做过层次遍历的就很清楚了。其他很多大神们的用了双端队列来解决，小弟就不献丑了。
```
public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList();
        Stack<TreeNode> stack = new Stack();
        List<List<Integer>> res = new ArrayList();
        if (root == null) return res;       
        int level = 0; // this marks the odd or even.
        // then lets go.
        queue.add(root);
        while (!queue.isEmpty()) {
            // if in even level.
            res.add(new ArrayList());
            int level_length = queue.size();
            if (level % 2 == 0) {
                for (int i = 0; i < level_length; i++) {
                    TreeNode node = queue.remove();
                    if (level == 0) {
                        res.get(level).add(node.val);
                    }
                    if (node.right != null) queue.add(node.right);
                    if (node.left != null) queue.add(node.left);
                }
                while (!stack.isEmpty()) {
                    res.get(level).add(stack.pop().val);
                }
            }else {
                for (int i = 0; i < level_length; i++) {
                    TreeNode node = queue.remove();
                    res.get(level).add(node.val);
                    
                    if (node.right != null) {
                        queue.add(node.right);
                        stack.push(node.right);
                    }
                    if (node.left != null) {
                        queue.add(node.left);
                        stack.push(node.left);
                    }
                }
            }
            level++;
        }
    
        return res;
    }
```
思路就是层次遍历，但是注意一下，奇数层的时候，是从右到左，偶数层是从左到右，所以用了栈来抄一下结果。
也算是完成了第一份题解。。。
