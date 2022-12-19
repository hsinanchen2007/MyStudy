#### 方法1：迭代法、DFS、仿先序遍历（区别：只有遇到叶子节点，才加入res中）。
思路：
1. 先用仿先序遍历获得root1的叶子序列，再用仿先序遍历依次获得root2的叶子值，
2. 每获得root2的一个叶子值都与root1的叶子序列的对应索引位置进行比较。
   - 相同(true)：则继续，
   - 不同(false)：则直接返回。
```
public boolean leafSimilar(TreeNode root1, TreeNode root2) {
    List<Integer> res = new ArrayList<>(); // root1的叶子序列值
    Stack<TreeNode> stack = new Stack<>();

    TreeNode node = root1;
    stack.push(node);
    while (!stack.isEmpty()) {
        node = stack.pop();
        // 只有遇到叶子节点，才加入res中
        if (node.left == null && node.right == null) res.add(node.val); 
        if (node.right != null) stack.push(node.right);
        if (node.left != null) stack.push(node.left);
    }
    
    int i = 0;
    node = root2;
    stack.push(node);
    while (!stack.isEmpty()) {
        node = stack.pop();
        // 核心判断逻辑
        if (node.left == null && node.right == null && node.val != res.get(i++)) return false; 
        if (node.right != null) stack.push(node.right);
        if (node.left != null) stack.push(node.left);
    }
    return true;
}
```

#### 方法2：递归法、DFS
```
public boolean leafSimilar(TreeNode root1, TreeNode root2) { 
    List<Integer> res1 = new ArrayList<>();
	List<Integer> res2 = new ArrayList<>();    
    dfs(root1, res1);
    dfs(root2, res2);
    return res1.equals(res2);
}
public void dfs(TreeNode node, List<Integer> res) { 
	if (node == null) return;
    if (node.left == null && node.right == null) res.add(node.val);
    dfs(node.left, res);
    dfs(node.right, res);
}
```

