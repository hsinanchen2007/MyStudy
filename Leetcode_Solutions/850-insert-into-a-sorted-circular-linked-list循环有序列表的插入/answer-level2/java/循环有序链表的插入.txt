### 解题思路
此处撰写解题思路

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
    //思路： 要插入的元素有以下三种状况
    //1.要插入的元素处于两个节点元素的中间
    //2. 插入的是走愈大的元素  3.插入的是最小的元素
    public Node insert(Node head, int insertVal) {
        if(head==null)
        {
            //给定的链表为空，创建循环链表并返回
            Node node=new Node(insertVal);
            node.next=node;
            return node;
        }

        Node curr=head;
        while(curr.next!=head)
        {
            if(insertVal>=curr.val&&insertVal<=curr.next.val)
            {
                break;
            }
            else if(curr.val>curr.next.val&&insertVal>=curr.val)  //插入最大值
                break;
            else if(curr.val>curr.next.val&&insertVal<=curr.next.val)  //插入最小值
                break;
            curr=curr.next;
        }
        //插入节点
        Node next=curr.next;
        Node insertNode=new Node(insertVal);
        insertNode.next=next;
        curr.next=insertNode;
        return head;
    }
}
```