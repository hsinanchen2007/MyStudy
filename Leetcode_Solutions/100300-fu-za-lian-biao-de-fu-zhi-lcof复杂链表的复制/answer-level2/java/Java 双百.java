### 解题思路
    克隆问题一般都是要每个节点都要new一个新的节点。先要复制节点，然后复制next指针和random指针。怎么存储新旧节点之间对应的关系？需要用到hashmap<oldnode,newnode>数据结构,刚开始我是将复制节点和指针分开来操作，但是超时啦，所以想着怎么能在复制节点的同时又能复制指针，hashmap里不但存储<oldnode,newnode>还要存着<oldnode.random,newnode.random> 其实这两个表示方法都是一样的，新旧节点的对应关系，所以我们要判断一下，如果map里已经有了新节点的话，那我就不需要再new，直接拿出来赋值给newnode。具体方式看代码注解。

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
        if(head ==null) return null;
        Map<Node,Node> map= new HashMap<Node,Node>();
        Node dummy =new Node(0);
        Node pre=dummy,newnode;
         
        while(head!=null){
            //1.复制节点
            if(map.containsKey(head)){
                newnode = map.get(head);
            }else{
                newnode = new Node(head.val);
                map.put(head,newnode);
            }
            pre.next=newnode;
            //2.复制随机指针
            if(head.random!=null){
                if(map.containsKey(head.random)){
                  newnode.random = map.get(head.random);
                }else{
                    newnode.random = new Node(head.random.val);
                    map.put(head.random,newnode.random);
                }
            }
            //3.复制next指针
            pre = newnode;
            //head下移
            head=head.next;
        }

        return dummy.next;
    }
}
```