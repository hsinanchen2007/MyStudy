### 思路：
- 多级链表结构的扁平化类似二叉树的先序遍历
- child就相当于left tree，next相当于right tree
- 需要维护一个prev指针用于访问当前节点的上一个节点
- prev指针非空时，建立prev与当前节点的双向连接
- 处理完一个child后记得把它设为null

### 代码：
```java
class Solution {
    private Node prev = null;
    public Node flatten(Node head) {
        dfs(head);
        return head;
    }
    
    private void dfs(Node head) {
        if (head == null) return;
        Node next = head.next;
        if (prev != null) {
            prev.next = head;
            head.prev = prev;
        }
        prev = head;
        dfs(head.child);
        head.child = null;
        dfs(next);
    }
}
```