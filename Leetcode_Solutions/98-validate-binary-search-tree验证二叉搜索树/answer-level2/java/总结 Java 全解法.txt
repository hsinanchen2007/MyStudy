我们从简单的**前序递归**开始
```
class Solution {
    public boolean isValidBST(TreeNode root) {
        return dfs(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    boolean dfs(TreeNode node, long lower, long upper) {
        if (node == null) 
            return true;
        if (node.val <= lower) 
            return false;
        if (node.val >= upper) 
            return false;
        if (!dfs(node.left, lower, node.val)) 
            return false;
        if (!dfs(node.right, node.val, upper)) 
            return false;
        return true;
    }
}
```
写花哨一点是：
```
class Solution {
    public boolean isValidBST(TreeNode root) {
        return dfs(root, java.lang.Long.MIN_VALUE, java.lang.Long.MAX_VALUE);
    }
    boolean dfs(TreeNode node, long min, long max) {
        return (node == null) || node.val > min && node.val < max && dfs(node.left, min, node.val) && dfs(node.right, node.val, max);
    }
}
```
如果不用递归，而用**栈**实现**前序**：
```
class Solution {
    Stack<TreeNode> st = new Stack<>();
    Stack<Long> upperList = new Stack<>(), 
        lowerList = new Stack<>();
        
    public boolean isValidBST(TreeNode root) {
        long lower = Long.MIN_VALUE, upper = Long.MAX_VALUE, val;
        update(root, lower, upper);
        while (!st.empty()) {
            root = st.pop();
            lower = lowerList.pop();
            upper = upperList.pop();
            if (root == null) continue;
            val = (long)root.val;
            if (val <= lower) return false;
            if (val >= upper) return false;
            update(root.right, val, upper);
            update(root.left, lower, val);
        }
        return true;
    }

    void update(TreeNode node, long lower, long upper) {
        st.push(node);
        lowerList.push(lower);
        upperList.push(upper);
    }
}
```
仅仅将栈改为队列，就实现了**广度优先**：
```
class Solution {
    Queue<TreeNode> queue = new LinkedList<>();
    Queue<Long> upperList = new LinkedList<>(), 
        lowerList = new LinkedList<>();
        
    public boolean isValidBST(TreeNode root) {
        long lower = Long.MIN_VALUE, upper = Long.MAX_VALUE, val;
        update(root, lower, upper);
        while (!queue.isEmpty()) {
            root = queue.poll();
            lower = lowerList.poll();
            upper = upperList.poll();
            if (root == null) continue;
            val = root.val;
            if (val <= lower) return false;
            if (val >= upper) return false;
            update(root.left, lower, val);
            update(root.right, val, upper);
        }
        return true;
    }

    void update(TreeNode root, long lower, long upper) {
        queue.offer(root);
        lowerList.offer(lower);
        upperList.offer(upper);
    }
}
```
现在换回栈，但改用**中序**排序
```
class Solution {
    public boolean isValidBST(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        long lastVal = Long.MIN_VALUE;
        
        while (!st.empty() || root != null) {
            while(root != null) {
                st.push(root);
                root = root.left;
            }
            root = st.pop();
            if (root.val <= lastVal) return false;
            lastVal = (long)root.val;
            root = root.right;
        }
        return true;
    }
}
```
用**递归**来实现**中序**，往上翻看看和**前序递归**有什么区别，想一想为什么**中序**只需判断一次节点值的大小
```
class Solution {
    long lastVal = Long.MIN_VALUE;
    public boolean isValidBST(TreeNode root) {
        return dfs(root);
    }
    boolean dfs(TreeNode node) {
        if (node == null)
            return true;
        if (!dfs(node.left))
            return false;
        if (node.val <= lastVal) 
            return false;
        lastVal = (long) node.val;
        if (!dfs(node.right))
            return false;
        return true;
    }
}
```
dfs和isValidBST 在参数返回值一致，可以把这两个合并为一个
```
class Solution {
    long lastVal = Long.MIN_VALUE;
    public boolean isValidBST(TreeNode root) {
        if (root == null)
            return true;
        if (!isValidBST(root.left))
            return false;
        if (root.val <= lastVal) 
            return false;
        lastVal = (long) root.val;
        if (!isValidBST(root.right))
            return false;
        return true;
    }
}
```
写得花哨一点就只剩一行
```
class Solution {
    long lastVal = Long.MIN_VALUE;
    public boolean isValidBST(TreeNode root) {
        return (root == null) || (isValidBST(root.left) && lastVal < (lastVal = root.val) && isValidBST(root.right));
    }
}
```