```java
    /*
     * Runtime: 1 ms, faster than 89.76% of Java online submissions for Binary
     * Tree Right Side View.
     * Memory Usage: 36.1 MB, less than 99.98% of Java online submissions for
     * Binary Tree Right Side
     * 层次遍历
     */
    class Solution {
        public List<Integer> rightSideView(TreeNode root) {
            List<Integer> res = new ArrayList<Integer>();
            if (root == null) {
                return res;
            }
            Queue<TreeNode> queue = new LinkedList<TreeNode>();
            queue.offer(root);
            queue.offer(null);
            while (!queue.isEmpty()) {
                TreeNode node = queue.poll();
                TreeNode peek = queue.peek();
                if (node == null) {
                    if (peek == null) {
                        break;
                    }
                    queue.offer(null);
                } else {
                    if (node.left != null) {
                        queue.offer(node.left);
                    }
                    if (node.right != null) {
                        queue.offer(node.right);
                    }
                    if (peek == null) {
                        res.add(node.val);
                    }
                }
            }
            return res;
        }
    }

    /*
     * Runtime: 1 ms, faster than 89.76% of Java online submissions for Binary 
     * Tree Right Side View.
     * Memory Usage: 36 MB, less than 99.98% of Java online submissions for 
     * Binary Tree Right Side View.
     * DFS
     */
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if (root == null) {
            return res;
        }
        dfs(root, 0, res);
        return res;
    }

    private void dfs(TreeNode node, int level, List<Integer> res) {
        if (node == null) {
            return;
        }
        if (res.size() == level) {
            res.add(node.val);
        }
        dfs(node.right, level + 1, res);
        dfs(node.left, level + 1, res);
    }
```