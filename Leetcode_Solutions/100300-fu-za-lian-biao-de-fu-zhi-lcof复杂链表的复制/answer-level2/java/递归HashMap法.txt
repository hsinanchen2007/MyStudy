

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
        //map的Key为旧节点的值，Value为新节点的值
        Map<Node,Node> map = new HashMap<>();
        //先放入空指针
        map.put(null,null);
        return helper(map,head);
    }
    public Node helper(Map<Node,Node> map,Node head){
        if(map.containsKey(head)){
            return map.get(head);
        }else{
            Node newNode = new Node(head.val);
            map.put(head,newNode);
            newNode.next = helper(map,head.next);
            newNode.random = helper(map,head.random);
            return newNode;
        }
    }
}
```