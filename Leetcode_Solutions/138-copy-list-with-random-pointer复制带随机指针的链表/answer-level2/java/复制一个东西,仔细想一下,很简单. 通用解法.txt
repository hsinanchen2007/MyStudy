### 解题思路
复制一个东西, 仔细想一下, 很简单, 只需要把每个节点复制, 然后组装每个节点.这是通用解法

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
        if (head == null) return null;
        /**
         * 怎么复制一个东西？
         * 1，复制每个节点
         * 2，组装节点之间的关系
         *
         */

        //1,复制每个节点. 用list来记录顺序, 用map来记录老的节点和新节点的对应关系
        Node root = head;
        ArrayList<Node> list = new ArrayList<>();
        ArrayList<Node> list1 = new ArrayList<>();
        HashMap<Node, Node> map = new HashMap<>();
        while (root != null) {
            Node tmp = copy(root);
            list.add(tmp);
            list1.add(root);
            map.put(root, tmp);
            root = root.next;
        }
        // 组装关系
        for (int i = 0; i < list.size(); i++) {
            Node node = list.get(i);
            Node node1 = list1.get(i);
            Node next = map.get(node1.next);
            Node random = map.get(node1.random);
            node.next = next;
            node.random = random;
        }
        return list.get(0);
    }
    private Node copy(Node node) {
        if (node == null) return null;
        return new Node(node.val);
    }
}
```