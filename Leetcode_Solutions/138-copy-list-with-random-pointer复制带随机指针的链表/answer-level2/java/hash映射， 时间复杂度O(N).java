![新建 Microsoft Visio Drawing.jpg](https://pic.leetcode-cn.com/c1072e59ac3f7c3abb51afc1d634940b4852fe9dcc8b2e0e65be47bb81701b75-%E6%96%B0%E5%BB%BA%20Microsoft%20Visio%20Drawing.jpg)

```
class Solution {
    public Node copyRandomList(Node head) {
        Node h = new Node(); 
        Node q = h, p = head;  // 新、旧链表游标指针
        HashMap<Node,Node> nodeC = new HashMap<>(); //两条链表对应位置的映射关系

        while(p!=null){ //第一步 ，深拷贝，不包括random
            q.next = new Node();
            q.next.val = p.val;
            nodeC.put(p,q.next);
            q = q.next;
            p = p.next;
        }

        p = head; // 重置新、旧链表游标指针，从头开始。
        q = h.next;

        while(p!=null){ //第二步 ，根据映射关系，找到新链表的random
            q.random = nodeC.get(p.random);
            p=p.next;
            q=q.next;
        }

        return h.next;
    }
}
```
