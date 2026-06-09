执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
78.84%
的用户
内存消耗 :
36.1 MB
, 在所有 Java 提交中击败了
76.93%
的用户
```
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val,Node _left,Node _right,Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    LinkedList<Node> ll = new LinkedList<Node>();
    public Node connect(Node root) {
        if(root==null)return root;
        ll.add(root);
        while(!ll.isEmpty()){
            int size = ll.size();
            Node last = null;
            for(int i=0; i<size; i++){
                Node cur = ll.pop();
                if(last!=null){
                    last.next=cur;
                }
                last = cur;a
                if(cur.left!=null){
                    ll.add(cur.left);
                    ll.add(cur.right);
                }
            }
        }
        return root;
    }
}
```
