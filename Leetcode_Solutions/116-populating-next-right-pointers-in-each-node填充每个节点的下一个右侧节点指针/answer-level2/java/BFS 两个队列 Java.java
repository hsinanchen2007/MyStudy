```
class Solution {
    public Node connect(Node root) {
        if(root == null) {
            return root;
        }
        //两个队列
        LinkedList<Node> q1 = new LinkedList<>();
        LinkedList<Node> q2 = new LinkedList<>();
        q1.addLast(root);
        while(q1.size() > 0 || q2.size() > 0){
            while(q1.size() > 0) {
                Node node = q1.removeFirst();
                if(q1.size() != 0) {
                    node.next = q1.getFirst();        
                }
                if(node.left != null){
                    q2.addLast(node.left);
                    q2.addLast(node.right);
                }
            }
            while(q2.size() > 0) {
                Node node = q2.removeFirst();
                if(q2.size() != 0) {
                    node.next = q2.getFirst();        
                }
                if(node.left != null){
                    q1.addLast(node.left);
                    q1.addLast(node.right);
                }
            }
        }
        return root;
    }
}
```