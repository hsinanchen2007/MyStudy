### 解题思路
分三步走
1，复制链表节点
2，复制链表节点的random指针
3，分拆列表，深拷贝的那组链表返回

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
        //思路是-先复制一份链表 再拆分链接
        
        //链表为空
        if (head == null) {
            return null;
        }

        
        Node curr = head;//当前的指针
        Node next = head.next;//下一个指针

       //复制链表的节点并链接
        while (curr != null && next != null) {
            curr.next = new Node(curr.val);//复制节点
            curr.next.next = next;//将当前节点 - 复制节点 - 下一节点 链接起来
            //赋值到下一个节点
            curr = next;
            next = next.next;
        }
        //链接最后一个节点
        curr.next = new Node(curr.val);

        /*debug
        while (head != null) {
            System.out.println(head.val);
            head = head.next;
        }*/

        
        //将随机指针赋值
        Node currRandom = head;//当前的指针
        while (currRandom != null) {
            if (currRandom.random != null) {
                //debug
                //System.out.println(currRandom.val);
                //System.out.println(currRandom.random.val);
                currRandom.next.random = currRandom.random.next;
                //System.out.println(currRandom.next.val);
            }
            if (currRandom.next.next != null) {
                currRandom = currRandom.next.next;
            }  else {
                break;
            }
        }

        //拆分链表列表
        curr = head;
        Node copyHead = head.next;
        Node copyH    = null;
        while (curr != null) {
            next = curr.next.next;
            copyH = curr.next;
            curr.next = next;
            copyH.next   = (next != null) ? next.next : null;
            curr = next;
        } 

        /*while (copyH != null) {
            System.out.println(copyH.val);
            copyH = copyH.next;
        }*/


        return copyHead;
    }
}
```