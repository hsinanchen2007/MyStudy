### 解题思路
复杂链表的复制，主要时包含了一个random指针；
采用一个hashMap,将node 和 对应的node建立起对应的关系；
挺有的意思题目，标记了 后面会再来看看的

### 代码

```java
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
class Solution {
    public Node copyRandomList(Node head) {
        Map<Node,Node> map = new HashMap<>();
        Node node = head;
        while(node!=null){
            map.put(node,new Node(node.val));
            node = node.next;
        }
        node = head;
        while(node!=null){
            map.get(node).next = map.get(node.next);
            map.get(node).random = map.get(node.random);
            node = node.next;
        }
        return map.get(head);
    }
}
```