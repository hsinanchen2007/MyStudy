递归法 1ms, 迭代法 5ms

```java
    private boolean hasSum = false;

    /**
     * 递归法
     */
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }
        sum(root, sum, 0);
        return hasSum;
    }

    private void sum(TreeNode node, int sum, int cur) {
        if (node == null) {
            return;
        }
        cur += node.val;
        if (node.left == null && node.right == null) {
            if (sum == cur) {
                hasSum = true;
            }
        }
        sum(node.left, sum, cur);
        sum(node.right, sum, cur);
    }

    /**
     * 递归法
     * 官方题解中的答案, 比我自己写的要简洁
     */
    public boolean hasPathSum2(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }

        sum -= root.val;
        if ((root.left == null) && (root.right == null)) {
            return (sum == 0);
        }
        return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);
    }


    /**
     * 迭代法
     */
    public boolean hasPathSum3(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }
        Stack<TreeNode> nodeStack = new Stack<>();
        Stack<Integer> sumStack = new Stack<>();
        nodeStack.push(root);
        sumStack.push(sum);
        while (!nodeStack.isEmpty()) {
            TreeNode node = nodeStack.pop();
            Integer cur = sumStack.pop();
            cur -= node.val;
            if (node.right == null && node.left == null) {
                if (cur == 0) {
                    return true;
                }
            }

            if (node.right != null) {
                sumStack.push(cur);
                nodeStack.push(node.right);
            }
            if (node.left != null) {
                sumStack.push(cur);
                nodeStack.push(node.left);
            }
        }

        return false;
    }

```