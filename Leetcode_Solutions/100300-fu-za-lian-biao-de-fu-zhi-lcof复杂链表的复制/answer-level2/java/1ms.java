### 解题思路
此处撰写解题思路

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
        Node find=head;
        Node newOne=new Node(0),brother=newOne;
        HashMap<Node,Integer> original=new HashMap<>();//用来存放reference每个节点的序号
        HashMap<Integer,Node> map=new HashMap<>();//用来存储每个新序号下的节点
        int i=0;
        while (find!=null){//建立链表，把每个链表位置记录
            original.put(find,i);
            brother.next=new Node(find.val);
            map.put(i++,brother.next);
            brother=brother.next;
            find=find.next;
        }
        brother=newOne.next;
        find=head;
        while (find!=null){//部署random
            if (find.random!=null) {
                brother.random = map.get(original.get(find.random));//旧序列当前节点的序号在新序列中所对应的节点即为当前新序列random
            }
            brother=brother.next;
            find=find.next;
        }
        return newOne.next;
    }
}
```