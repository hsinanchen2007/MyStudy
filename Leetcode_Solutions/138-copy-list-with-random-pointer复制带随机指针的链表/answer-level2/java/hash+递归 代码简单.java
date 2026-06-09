首先将该链表看成简单的链表，先沿着next指针对链表进行复制，并将复制的节点利用HashMap构建一个hash表。
然后进行random节点的构建，根据原链表的random节点的val去hash表中进行索引，检索到复制表中对应的节点。
对应代码如下：
```
Map<Integer, Node> map = new HashMap<>();
    public Node copyRandomList(Node head) {
        if (head == null) return null;
        Node cloneNode = new Node();
        cloneNode.val = head.val;
        map.put(cloneNode.val, cloneNode);

        // 相当于沿next链进行节点的复制
        cloneNode.next = (head.next == null ? null : copyRandomList(head.next));
        cloneNode.random = (head.random == null ? null : map.get(head.random.val));
        
        return cloneNode;
    }
```
