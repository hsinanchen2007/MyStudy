每一层先保存右节点，再保存左节点即可，也可以解决117题
```
class Solution {
    public Node connect(Node root) {
        if(root==null) return root;
        LinkedList<Node> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()) {
            int len = queue.size();
            Node next = null;
            for(int i=0; i<len; i++) {
                Node cur = queue.poll();
                if(cur.right!=null) queue.add(cur.right);
                if(cur.left!=null) queue.add(cur.left);
                cur.next = next;
                next = cur;
            }
        }
        return root;
    }
}
```
