### 解题思路

![image.png](https://pic.leetcode-cn.com/4d5b15e1d05f092d73a0b9b8f4aa2f9aa5523dac7806d9b4f02268e97bda9eb7-image.png)


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

        if(head == null){
            return null;
        }
        //复制节点 A->B->C 变成 A->A'->B->B'->C->C'
        Node pHead = head;
        while (pHead != null){
            Node node = new Node(pHead.val);
            node.next = pHead.next;
            pHead.next = node;
            pHead = node.next;
        }

        //复制random
        pHead = head;
        while (pHead !=null){
            pHead.next.random = pHead.random == null ? null : pHead.random.next;
            pHead = pHead.next.next;
        }

        //折分
        pHead = head;
        Node cpyHead = pHead.next;
        while (pHead!=null){
            Node node = pHead.next;
            pHead.next = node.next;
            node.next = node.next == null ? null : node.next.next;
            pHead = pHead.next;
        }
        return cpyHead;
    }
}
```

