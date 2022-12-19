### 解题思路
利用队列实现迭代解法
递归就是很普通的递归
### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        Queue<Node> queue = new LinkedList<>();
        // 将根结点加入到队列中
        queue.add(root);
        while (!queue.isEmpty()) {
            // 当前层的结点数目
            int count = queue.size();
            List<Integer> list = new ArrayList<>();
            while (count > 0) {
                // 将当前层结点的值加入到列表中
                Node node = queue.poll();
                list.add(node.val);
                count--;
                // 将子树的结点加入到队列中
                for (Node cur : node.children) {
                    // 对结点进行判断
                    if (cur != null) {
                        queue.add(cur);
                    }
                }
            }
            // 将每一层的结果汇总
            res.add(list);
        }
        return res;
    }
}
```

```java
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res = new ArrayList<>();
        helper(root, res, 0);
        return res;
    }
    
    private void helper(Node root, List<List<Integer>> res, int depth) {
        // 终止条件
        if (root == null) {
            return ;
        }
        if (res.size() <= depth) {
            res.add(new ArrayList<>());
        }
        // 按层添加元素
        res.get(depth).add(root.val);
        for (Node node : root.children) {
            helper(node, res, depth + 1);
        }
    }
}
```


