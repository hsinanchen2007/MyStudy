### 解题思路
这道题的本质就是要求我们把多层链表转换成一条平行链表，这里就意味着多级链表存在着链表的嵌套。
我们的目标去嵌套，那么就意味着我们需要一层一层的合并，毫无疑问，我会立马想到递归。

思路非常简单，我们抓住有子链表的节点，想办法，抓住子链表的头和尾，然后插入到当前链表出现子链表节点。
这里采用题目给的例子：

```
 1---2---3---4---5---6--NULL            1---2---3---4---5---6--NULL
         |                                      |
         7---8---9---10--NULL   ----->          7---11---12---8---9---10--NULL     
             |
             11--12--NULL



----->1-2-3-7-8-11-12-9-10-4-5-6-NULL

```


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
    public Node flatten(Node head) {
        Node p=head;
        while(p!=null)
        {
            if(p.child!= null)
            {
                Node r=p.next;
                p.next=p.child;
                p.child.prev=p;
                p.child=null;
                Node subt=searchTail(p.next);
                subt.next=r;
                if(r!=null)
                r.prev=subt;
                p=r;
            }
            else
            p=p.next;

        }
        return head;
    }
    public Node searchTail(Node head)
    {
        Node p=head;
        Node tail=head;
            while(p!= null){
            if(p.child!= null)//出现孩子
            {
                Node r=p.next;
                p.next=p.child;
                p.child.prev=p;
                p.child=null;
                Node subt=searchTail(p.next);//接收尾部
                subt.next=r;
                if(r!=null)
                r.prev=subt;
                p=r;
                if(r==null)
                tail=subt;//更新尾部
            }
            else
            {
                tail=p;//更新尾部
                p=p.next;
            }


        }
        return tail; //返回尾部
    }
}
```