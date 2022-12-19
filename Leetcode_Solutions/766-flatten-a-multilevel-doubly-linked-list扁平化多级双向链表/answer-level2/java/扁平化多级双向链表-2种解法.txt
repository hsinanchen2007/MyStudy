>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：递归实现

时间复杂度和空间复杂度均是O(n)，其中n为链表中的节点个数。

执行用时：0ms，击败100.00%。消耗内存：38MB，击败39.90%。

```java
public class Solution {
    public Node flatten(Node head) {
        if (null == head) {
            return null;
        }
        if (null == head.child) {
            Node node = flatten(head.next);
            if (null != node) {
                node.prev = head;
            }
            head.next = node;
            return head;
        }
        Node node1 = head.next, node2 = flatten(head.child);
        node2.prev = head;
        head.next = node2;
        head.child = null;
        Node cur = head;
        while (cur.next != null) {
            cur = cur.next;
        }
        if (null != node1) {
            node1.prev = cur;
        }
        cur.next = node1;
        return head;
    }
}
```

# 解法二：栈的应用

时间复杂度和空间复杂度均是O(n)，其中n为链表中的节点个数。

执行用时：1ms，击败31.20%。消耗内存：37.7MB，击败42.32%。

```java
public class Solution {
    public Node flatten(Node head) {
        if (null == head) {
            return null;
        }
        Node pre = null;
        Stack<Node> stack = new Stack<>();
        stack.push(head);
        while (!stack.isEmpty()) {
            Node cur = stack.pop();
            if (null != pre) {
                pre.next = cur;
            }
            cur.prev = pre;
            if (null != cur.next) {
                stack.push(cur.next);
            }
            if (null != cur.child) {
                stack.push(cur.child);
                cur.child = null;
            }
            pre = cur;
        }
        return head;
    }
}
```