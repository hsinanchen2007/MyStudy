# 解法一：广度优先遍历
```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new LinkedList<>();
        List<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (root != null && queue.size() != 0) {
            List<Integer> tmp = new ArrayList<>();
            int count = queue.size();
            while (count > 0) {
                root = queue.remove(0);
                tmp.add(root.val);
                if (root.left != null) {
                    queue.add(root.left);
                }
                if (root.right != null) {
                    queue.add(root.right);
                }
                count--;
            }
            list.add(tmp);
        }
        return list;
    }
}
```

# 解法二：递归地前序遍历
该方法仅最终展示结果正确，访问节点的顺序并不是层序遍历应有的顺序
```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new LinkedList<>();
        recursive(root, 1, list);
        return list;
    }

    private void recursive(TreeNode node, int level, List<List<Integer>> list) {
        if (node == null) return;
        if (list.size() < level) list.add(new ArrayList<Integer>());
        list.get(level - 1).add(node.val);
        recursive(node.left, level + 1, list);
        recursive(node.right, level + 1, list);
    }
}
```

# 解法三：迭代地前序遍历
该方法的思想和解法二完全一样，只不过用迭代的方式来前序遍历，用散列表存储该节点所在的层数
```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new LinkedList<>();
        Stack<TreeNode> stack = new Stack<>();
        Map<TreeNode, Integer> map = new HashMap<>();
        int level = 1;
        map.put(root, level);
        stack.push(root);
        while (root != null && !stack.empty()) {
            root = stack.pop();
            level = map.get(root);
            if (list.size() < level) list.add(new ArrayList<Integer>());
            list.get(level - 1).add(root.val);
            map.remove(root);
            if (root.right != null) {
                stack.push(root.right);
                map.put(root.right, level + 1);
            }
            if (root.left != null) {
                stack.push(root.left);
                map.put(root.left, level + 1);
            }
        }
        return list;
    }
}
```