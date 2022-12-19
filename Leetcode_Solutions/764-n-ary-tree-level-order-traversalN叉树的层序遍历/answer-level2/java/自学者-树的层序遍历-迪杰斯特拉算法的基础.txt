### 解题思路
* 编写题解是为了让层序遍历称为长期记忆
* 迪杰斯特拉算法的基础
* 使用队列进行一层一层进行计算
* 重点是在脑海里留下这个方案
* 之前有一个传入level的递归实现感觉比较土还是这个比较好

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
        List<List<Integer>> result = new ArrayList<>();
        if(null == root) {
            return result;
        }
        Deque<Node> queue = new LinkedList<>();
        queue.addLast(root);
        Node node;
        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> levelItems = new ArrayList<>();
            for(int i = 0; i < size; i++) {
                node = queue.pollFirst();
                for(Node subnode : node.children) {
                    queue.addLast(subnode);
                }    
                levelItems.add(node.val);
            }
            result.add(levelItems);
        }
        return result;
    }
}
```