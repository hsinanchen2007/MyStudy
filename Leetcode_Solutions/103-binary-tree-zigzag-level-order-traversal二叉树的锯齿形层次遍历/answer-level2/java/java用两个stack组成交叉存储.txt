把两个stack放在一个List里面。用flag来控制交叉选择。和上面同学用两个stack的方法思路是一样的。
```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new LinkedList<>();
        if (root == null) {
            return result;
        }
        TreeNode curr = root;
        List<Deque<TreeNode>> stacks = new LinkedList<>();
        stacks.add(new LinkedList<>());
        stacks.add(new LinkedList<>());
        int flag = 1;
        int levelSize = 1;
        stacks.get(flag).push(curr);
        while (!stacks.get(flag).isEmpty() || !stacks.get(1-flag).isEmpty()) {
            List<Integer> sub = new LinkedList<>();
            for (int i = 0; i < levelSize; i++) {
                curr = stacks.get(flag).pop();
                sub.add(curr.val);
                if (flag == 0) {
                    if (curr.right != null) {
                        stacks.get(1-flag).push(curr.right);
                    } 
                    if (curr.left != null) {
                        stacks.get(1-flag).push(curr.left);
                    }
                }
                else if (flag == 1) {
                    if (curr.left != null) {
                        stacks.get(1-flag).push(curr.left);
                    }
                    if (curr.right != null) {
                        stacks.get(1-flag).push(curr.right);
                    }
                }
            }
            levelSize = stacks.get(1-flag).size();
            flag = 1 -flag;
            result.add(sub);     
        }
        return result;
    }
}

```

