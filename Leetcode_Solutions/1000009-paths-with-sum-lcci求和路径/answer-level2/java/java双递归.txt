```
public int pathSum(TreeNode root, int sum) {
        int res = 0;
        res = pathSum(root, sum, res);
        return res;
    }

    public int pathSum(TreeNode root, int sum, int num) {
        if (root == null) return num;

        Stack<Integer> stack = new Stack<>();
        num = path(root, stack, sum, num);

        num = pathSum(root.left, sum, num);
        num = pathSum(root.right, sum, num);
        return num;
    }

    public int path(TreeNode root, Stack<Integer> stack, int sum, int num) {
        if (root == null) return num;

        stack.push(root.val);
        int pathSum = 0;
        for (Integer integer : stack) {
            pathSum += integer;
        }
        if (pathSum == sum) num ++;

        num = path(root.left, stack, sum, num);
        num = path(root.right, stack, sum, num);

        stack.pop();
        return num;
    }

```
