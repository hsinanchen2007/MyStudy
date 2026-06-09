### 解题思路
利用原链表的next指针指向拷贝节点
 * 链表编织 再拆分
 * 每一个节点next都跟着复制自己的节点
 * 先拆random连接 复制节点 的random指向其指向的原节点的next（即复制节点）
 * 再拆next，每一个节点next都指向其原来指向的下一跳

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
        Node p = head;
        while (p!=null) {
            Node cur = p;
            p = p.next;
            Node copy = copy(cur);
            cur.next = copy;
        }
        p = head;
        for (int i=0;p!=null;i++,p=p.next) {
            // 复制的节点
            if ((i&1) == 1) {
                if (p.random!=null) {
                    p.random = p.random.next;
                }
            }
        }
        p = head;
        Node newHead = p.next;
        while (p!=null) {
            Node cur = p;
            p = p.next;
            if (cur.next!=null) {
                cur.next = cur.next.next;
            }

        }
        return newHead;
    }
    private Node copy(Node node) {
        Node newNode = new Node(node.val);
        newNode.next = node.next;
        newNode.random = node.random;
        return newNode;
    }
}
```
![image.png](https://pic.leetcode-cn.com/bf04aac8bdd9990d62ddec219a0b42b1311cd854e3bc770051c5875cadbbb4d9-image.png)
