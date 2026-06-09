这道题我觉得迭代的思路比较好理解。

从根节点开始，用`队列`存储每一层的节点，将这些节点的值存到结果中

同时取这些节点的左右儿子放到一个新的`队列`中，

然后用新队列更新原队列，再次遍历，不断循环得到结果。

```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
      	// 存储每一层的节点
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty() || root != null) {
          	// 每一层节点的值
            List<Integer> line = new ArrayList<>();
          	// 	存储下一行的节点
            Queue<TreeNode> tmp = new LinkedList<>();
          	// 遍历该行的每一个节点
            while (!q.isEmpty()) {
                root = q.poll();
              	// 当节点非空时，取出该节点的值，将其左右儿子存储到暂存队列中
                if (root != null) {
                    line.add(root.val);
                    tmp.offer(root.left);
                    tmp.offer(root.right);
                }
            }
          	// 暂存队列为空时，说明该层已经是最底层，没有下一层了。
            if (line.isEmpty()) break;
          	// 加入结果
            res.add(line);
          	// 将下一层的节点更新为这一层
            while (!tmp.isEmpty()) {
                q.offer(tmp.poll());
            }
        }
        return res;
    }
}
```

当然还可以优化一下，如果每次记录好当前层的节点数，那么就可以控制遍历的次数，不需要用一个额外的`Queue`取存下一行的节点了。

```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            List<Integer> level = new ArrayList<>();
            // 存储当前层的节点数
            int len = q.size();
            // 遍历当前层的每一个节点
            for (int i=0; i<len; i++) {
                // 对于当前层的每一个节点，将值加入结果，并取其非空左右儿子加入队列
                // 由于提前确定了遍历的个数，所以后续加入的节点不会被遍历到，而是要到下一层的循环时才会被遍历
                root = q.poll();
                level.add(root.val);
                if (root.left != null) q.offer(root.left);
                if (root.right != null) q.offer(root.right);
            }
            res.add(level);
        }
        return res;
    }
}
```