主要是针对random指针的处理。
基本思想是：random指针如果指向已拷贝过的元素就直接指；如果指向的是还未拷贝的元素就先将其new出来，然后指向它。需要拷贝的时候再判断是否存在。

```
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

public class Solution {
    public Node copyRandomList(Node head) {
        
        //只需遍历一趟老链表。
        //保存为<老节点，新节点>

        Map<Node, Node> map = new HashMap<>();
        Node p = head;
        Node newHead = new Node(0);     //伪头结点,解决链表为空的问题
        Node current = newHead;
        while (p != null){
            //确定新节点是取还是new。如果是new就要存入哈希表
            Node newNode;
            if(map.get(p) == null){
                newNode = new Node(p.val);
                map.put(p, newNode);
            }else{
                newNode = map.get(p);
            }

            //确定random指针指向的对象是取还是new。如果是new就要存入哈希表
            if(p.random == null){
                newNode.random = null;
            }else {
                if (map.get(p.random) == null) {
                    Node randomNode = new Node(p.random.val);
                    map.put(p.random, randomNode);
                    newNode.random = randomNode;
                }else{
                    newNode.random = map.get(p.random);
                }
            }

            current.next = newNode;
            current = current.next;
            p = p.next;
        }
        return newHead.next;
    }
}
```
