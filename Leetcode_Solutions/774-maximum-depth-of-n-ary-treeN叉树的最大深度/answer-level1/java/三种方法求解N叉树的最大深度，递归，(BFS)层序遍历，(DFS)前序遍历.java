N叉树和二叉树求最大深度的步骤差不读，只不过二叉树只有左右两个孩子节点，而N叉树最多有N个孩子节点，因此只要遍历所有的孩子同时并找到最大值即可
```java
class Solution {
    public int maxDepth(Node root) {
        int max = 0;
        if (root == null) {
            return 0;
        } else if (root.children.isEmpty()) {
            return 1;
        } else {
            for (Node child : root.children) {
                max = Math.max(max, maxDepth(child) + 1);
            }
        }
        return max;
    }
}
```
BFS层序遍历，使用队列模拟递归的过程（迭代）
```java
import java.util.AbstractMap;
import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    public int maxDepth(Node root) {
        if (root == null) {
            return 0;
        } else if (root.children.isEmpty()) {
            return 1;
        }

        Queue<AbstractMap.SimpleEntry<Node, Integer>> queue = new ArrayDeque<>();
        queue.offer(new AbstractMap.SimpleEntry<>(root, 1));
        int depth = 0;
        while (!queue.isEmpty()) {
            AbstractMap.SimpleEntry<Node, Integer> curDepth = queue.poll();
            root = curDepth.getKey();
            if (root != null) {
                depth = Math.max(depth, curDepth.getValue());
                for (Node child : root.children) {
                    queue.offer(new AbstractMap.SimpleEntry<>(child, depth + 1));
                }
            }
        }
        return depth;
    }
}
```
DFS前序遍历，使用栈进行迭代
```java
import java.util.AbstractMap;
import java.util.Stack;

class Solution {
    public int maxDepth(Node root) {
        if (root == null) {
            return 0;
        } else if (root.children.isEmpty()) {
            return 1;
        }
        Stack<AbstractMap.SimpleEntry<Node, Integer>> stack = new Stack<>();
        stack.push(new AbstractMap.SimpleEntry<>(root, 1));
        int depth = 0;
        while (!stack.isEmpty()) {
            AbstractMap.SimpleEntry<Node, Integer> curDepth = stack.pop();
            root = curDepth.getKey();
            depth = Math.max(depth, curDepth.getValue());
            if (!root.children.isEmpty()) {
                for (Node child : root.children) {
                    stack.push(new AbstractMap.SimpleEntry<>(child, curDepth.getValue() + 1));
                }
            }
        }
        return depth;
    }
}
```