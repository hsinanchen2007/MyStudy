```
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        if(root == null)
            return new LinkedList<List<Integer>>();
        LinkedList<Node> q1 = new LinkedList<>();
        LinkedList<Node> q2 = new LinkedList<>();
        q1.add(root);
        List<List<Integer>> res = new LinkedList<List<Integer>>();
        while(q1.size() != 0 || q2.size() != 0){
            List<Integer> list = new LinkedList<>();
            if(q1.size() != 0){
                while(q1.size() != 0){
                    Node node = q1.removeFirst();
                    list.add(node.val);
                    for(Node n : node.children)
                        q2.addLast(n);
                }
            }
            else{
                while(q2.size() != 0){
                    Node node = q2.removeFirst();
                    list.add(node.val);
                    for(Node n : node.children)
                        q1.addLast(n);
                }
            }
            res.add(list);
        }
        return res;
    }
}
```