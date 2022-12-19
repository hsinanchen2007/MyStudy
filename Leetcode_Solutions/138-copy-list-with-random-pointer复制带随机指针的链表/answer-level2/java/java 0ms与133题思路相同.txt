### 解题思路
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
    HashMap<Node,Node> hash=new HashMap<>();
    public Node copyRandomList(Node head) {        
        if(head==null)
        return null;
        if(hash.containsKey(head))//如果已经克隆过了直接返回克隆的点
         return hash.get(head);
        else
        {
         Node clone=new Node(head.val);
         hash.put(head,clone);
         clone.random=copyRandomList(head.random);
         clone.next=copyRandomList(head.next);
         //否则克隆当前节点,递归设置next和random  
         return clone;
        }    
    }
}
```