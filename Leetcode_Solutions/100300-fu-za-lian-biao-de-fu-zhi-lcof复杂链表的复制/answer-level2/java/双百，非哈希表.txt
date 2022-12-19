### 解题思路
三步：
1：间隔合并原链表和复制链表
2：将复制链表的各结点指向正确的位置
3：拆分两个链表

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
       if(head==null){//如果为空链表就返回null
                return null;
            }
            Node cur = head;
            while (cur != null) {//将每个原结点后添加一个新的复制结点，新的复制结点的next指向下一个原结点，
                                 // random均指向一个new的val为0的结点
              Node turn=cur.next;
              Node newH= new Node(0);
              newH.val=cur.val;
              newH.random= new Node(0);
              cur.next=newH;
              newH.next=turn;
              cur=turn;
            }
            cur=head;
            while(cur!=null){//将复制结点的random域指向正确的位置
                cur.next.random=cur.random==null?null:cur.random.next;
                cur=cur.next.next;
            }
            cur=head;
            Node newHand =new Node(0);
            newHand.next=cur.next;//指向第一个复制结点
            while(cur!=null) {//指的是原结点
               if(cur.next.next!=null) {//这里的cur.next.next指的都是原结点
                   Node tem = cur.next.next;//存储下一个原结点位置
                   cur.next.next = cur.next.next.next;//将上一个复制结点的next域指向下一个复制结点
                   cur.next = tem;//原结点指向下一个原结点
                   cur = cur.next;//原结点后移
               }else{//如果原结点到达最后，就将原结点的next域置null
                   cur.next=cur.next.next;
                   break;
               }
            }
            return newHand.next;
    
    }
}
```