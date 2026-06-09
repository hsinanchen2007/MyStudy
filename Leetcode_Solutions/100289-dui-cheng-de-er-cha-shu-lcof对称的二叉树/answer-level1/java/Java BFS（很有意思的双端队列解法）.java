DFS自不必说，就是想试试BFS的写法。
起初用Queue实现了一个（一层放到一个数组，然后头尾指针判断），后来想想既然是对称，那么Deque就是再合适不过的数据结构了，代码如下：
```java
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null || root.left == root.right) return true;
        Deque<TreeNode> deque = new LinkedList<>();
        deque.addFirst(root.left);
        deque.addLast(root.right);
        while (!deque.isEmpty()) {
            // 因为是两端对称入队，所以获取的时候永远两端出队即可，并不需要考虑层级先后
            TreeNode head = deque.removeFirst(), tail = deque.removeLast();
            if (head == tail) continue;
            if (head == null || tail == null || head.val != tail.val) return false;
            // 注意首尾左右顺序，要对称着放入队列
            deque.addFirst(head.left);
            deque.addFirst(head.right);
            deque.addLast(tail.right);
            deque.addLast(tail.left);
        }
        return true;
    }
}
```
