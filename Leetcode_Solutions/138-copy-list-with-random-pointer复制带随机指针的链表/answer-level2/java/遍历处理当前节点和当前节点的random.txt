执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
34 MB
, 在所有 Java 提交中击败了
69.26%
的用户
```
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
        Node newh = new Node(0,null,null);
        Map<Node,Node> map = new HashMap<Node,Node>();
        Node temp = head;
        Node newt = newh;
        while(temp!=null){
            if(map.get(temp)==null){
                Node node = new Node(temp.val,null,null);
                newt.next = node;
                newt = node;
                map.put(temp,node);
            }else{
                Node nn = map.get(temp);
                newt.next = nn;
                newt = nn;
            }
            
           if(temp.random!=null){
                Node zz = map.get(temp.random);
                if(zz==null){
                    Node rr = new Node(temp.random.val,null,null);
                    map.put(temp.random,rr);
                    newt.random = rr;
                }else{
                    newt.random = zz;
                }
            }
            temp = temp.next;
        }
        return newh.next;
    }
}
```
