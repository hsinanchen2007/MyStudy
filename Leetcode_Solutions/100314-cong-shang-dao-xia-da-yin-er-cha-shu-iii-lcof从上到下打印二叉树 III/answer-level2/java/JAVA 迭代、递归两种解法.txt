递归
```java
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return new ArrayList<>();
        
        helper(root, 0);
        return res;
    }
    
    private void helper(TreeNode node, int level) {
        if (res.size() == level) {
            res.add(new ArrayList<>());
        }
        
        if (level % 2 == 0) {
            res.get(level).add(node.val);
        } else {
            res.get(level).add(0, node.val);
        }
        
        if (node.left != null) helper(node.left, level + 1);
        if (node.right != null) helper(node.right, level + 1);
    }
}
```

迭代
```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        Deque<TreeNode> deque = new LinkedList<>();
        deque.addLast(root);
        int level = 0;
        while (!deque.isEmpty()) {
            int length = deque.size();
            ans.add(new ArrayList<>());
            for (int i = 0; i < length; i ++) {
                TreeNode node = deque.pollFirst();
                if (level % 2 == 0) {
                    ans.get(level).add(node.val);
                } else {
                    ans.get(level).add(0, node.val);
                }
                
                if (node.left != null) deque.addLast(node.left);
                if (node.right != null) deque.addLast(node.right);
            }
            level ++;
        }
        return ans;
    }
}
```
