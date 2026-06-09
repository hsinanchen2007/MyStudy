### 解题思路
    不使用hashmap，只用一种很巧妙的方式解决,
    1.在原有的链表中插进新的节点1‘，2’，3‘
       1-》2-》3-》null
       1-》1’-》2-》2‘-》3-》3’-》null
    2.复制随机指针 head.random 的next 就是head.next.random的值，即旧节点的随机值得下一个节点是新节点的随机值，比如1-》3，那么1’-》3‘
    3.将链表拆分成两个新的链表，提取出新的链表头返回。

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
// no hashmap
class Solution {
    public Node copyRandomList(Node head) {
        if(head ==null) return null;
        copyNext(head);
        copyRandom(head);
        return splitList(head);
    }
    public void copyNext(Node head){
        while(head!=null){
            Node newnode = new Node(head.val);
            newnode.next=head.next;
            newnode.random=head.random;
            head.next = newnode;
            head=head.next.next;
        }
    }
    public void copyRandom(Node head){
        while(head!=null){
            if(head.random!=null){
                head.next.random=head.random.next;
            }
            head = head.next.next;
        }
    }
    public Node splitList(Node head){
        Node dummy=new Node(0);
        dummy.next = head.next;
        while(head!=null){
            Node newnode = head.next;
            head.next = newnode.next;
            head=head.next;
            if(newnode.next!=null){
                newnode.next=newnode.next.next;
            }
        }
        return dummy.next;
    }
}
```