## 思路分析
在不利用额外空间的情况下，直接在链表上修改，若将此题简化，则等同于“深拷贝链表”.

如 1->2>3>4>5, 拷贝过程如下：
1. 拷贝节点值，原链表被修改为：1->1'->2->2'->3->3'->4->4'->5->5'
2. 拆分链表，原链表：1->2->3->4->5， 新链表：1'->2'->3'->4'->5'

由此可见，本题多附带了随机指针，那么，只需要在第一步和第二步之间加入“copy节点的随机指针的指向”即可。

此题还可扩展为附带任何属性的链表进行深拷贝，比如双向链表。

## 代码实现
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
    public Node copyRandomList(Node head) {
        if(head==null) return head;
        // 拷贝值
        Node p = head;
        while(p!=null){
            Node temp = p.next, copy = new Node(p.val,null,null);
            p.next = copy;
            p.next.next = temp;
            p = temp;
        }
        // copy节点随机指针指向
        p = head;
        while(p!=null&&p.next!=null){
            Node copy = p.next;
            if(p.random==p) {
                copy.random = copy;
            }else {
                copy.random = p.random==null?null:p.random.next;
            }
            p = copy.next;
        }
        
        // 链表拆分
        p = head;
        Node start = new Node();
        Node q = start;
        while(p!=null&&p.next!=null){
            Node temp = p.next.next;
            q.next = p.next;
            p.next = temp;
            p = temp;
            q = q.next;
        }
        return start.next;
    }
}
```