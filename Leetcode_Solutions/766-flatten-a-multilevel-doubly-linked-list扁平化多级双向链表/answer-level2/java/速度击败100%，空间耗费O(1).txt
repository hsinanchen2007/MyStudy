### 解题思路
通过类似树的后序遍历，再结合头插法解决本题
![430.扁平化多级双向链表.png](https://pic.leetcode-cn.com/5be76910aa7b55ed34b19f2acebb3326070cf77a2ad7c8744b224ef6c8ee57fd-430.%E6%89%81%E5%B9%B3%E5%8C%96%E5%A4%9A%E7%BA%A7%E5%8F%8C%E5%90%91%E9%93%BE%E8%A1%A8.png)

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/
class Solution {

    Node dummy;

    public Node flatten(Node head) {
        if(head == null) return head;
        dummy = new Node();

        helper(head);

        head.prev = null;
        dummy.next = null;
        return head;
    }

    private void helper(Node node) {
        if(node == null) return;
        helper(node.next);
        helper(node.child);

        node.prev = dummy;
        node.next = dummy.next;  
        if(dummy.next != null) dummy.next.prev = node;
        dummy.next = node;

        node.child = null;
    }
}
```