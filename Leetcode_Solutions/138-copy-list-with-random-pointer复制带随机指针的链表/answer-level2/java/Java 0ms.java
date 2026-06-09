### 解题思路
原地炸裂，哈哈，总算有道题会做了，新Node的random肯定需要一个旧Node的random来指明，所以也就想到了原地复制一个插入next，之后再分割就好了。

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
        if (head==null) return null;
        copyNext(head);
        copyRandom(head);
        return separate(head);
    }
    
    private void copyNext(Node head){
        if (head==null) return;
        Node copyHead = new Node(head.val);
        copyHead.next = head.next;
        head.next = copyHead;
        copyNext(head.next.next);
    }
    private void copyRandom(Node head){
        if (head==null) return;
        if (head.random==null) head.next.random=null;
        else head.next.random = head.random.next;
        copyRandom(head.next.next);
    }
    private Node separate(Node head){
        Node cmp=head;
        Node res=head.next;
        while (cmp.next!=null){
            Node tmp = cmp.next;
            cmp.next = cmp.next.next;
            cmp = tmp;
        }
        return res;
    }
}
```