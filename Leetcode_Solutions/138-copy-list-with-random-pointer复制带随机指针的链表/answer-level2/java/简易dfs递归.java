### 解题思路
使用dfs的时候，由于`random`有可能指向前面已经被copy过的节点，所以必须使用一个哈稀映射来存储已经copy过的节点;最简单的一种映射就是<原节点，拷贝节点>，这样，每次调用拷贝递归函数`copyRandomList`时，只需要判断要拷贝的原节点是否存在于map中，存在则无需再次copy。
### 代码

```java

class Solution {
    //map's element means [orignal node,clone node]
    private Map<Node,Node> map=new HashMap<>();

    public Node copyRandomList(Node head) 
    {

        if(head==null)return null;

        //orignal Node head has been cloned,return its clone.
        if(map.containsKey(head))
            return map.get(head);

        Node clone=new Node(head.val);
        map.put(head,clone);

        clone.next=copyRandomList(head.next);
        clone.random=copyRandomList(head.random);

        return clone;
    }
}
```