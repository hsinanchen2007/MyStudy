### 解题思路
复杂问题简单化：可用将问题分解成三步
1.复制原链表
2.复制链表中复制节点的随机指向复制
3.拆分复制链表

此方法时间复杂度O(n)，
也可用哈希表存储法，时间复杂度相同，但是需要一个哈希表，空间复杂度O(n),哈希表的key是节点，value是随机指向的节点

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
        if(head==null)return null;
        copy(head);
        copyRandom(head);
        return reList(head);
    }
    private void copy(Node head){//复制原链表按A,A',B,B'顺序
        while(head!=null){
            Node clone=new Node(head.val);   //克隆节点头
            clone.next=head.next;//链接A’和B
            head.next=clone;//A指向A‘
            head=clone.next;//头指针移到B
        }
    }
    private void copyRandom(Node head){//复制原链表中随机指向
        while(head!=null){
            Node clone=head.next; //克隆节点头A’
            if(head.random!=null)
            clone.random=head.random.next;//头节点随机指向的下一个节点就是克隆节点的随机指向
            head=clone.next;
        }
    }
    private Node reList(Node head){
        Node clone=head.next;//复制链表的表头节点
        Node clonep=clone;//表头节点用于返回的，因为clone是用来移动的，所以需要一个clonep返回头
        head.next=clone.next;
        head=head.next;//指针移动到下一个头节点
        while(head!=null){
            clone.next=head.next;//复制链表的拼接
            clone=clone.next;//克隆指针移动
            head.next=clone.next;
            head=head.next;//头指针移动
        }
        return clonep;
    }
}
```