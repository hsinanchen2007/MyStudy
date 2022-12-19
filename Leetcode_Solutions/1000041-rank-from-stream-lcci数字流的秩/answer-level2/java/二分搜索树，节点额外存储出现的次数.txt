
```
class StreamRank {
    private class Node{
        public Node left, right;
        int val;
        int nums;
        public Node(int val){
            this.val = val;
            nums = 1;
            left = null;
            right = null;
        }
    }
    private Node root;

    public StreamRank() {
        root = null;
    }
    
    public void track(int x) {
        root = add(root, x);
    }
    public Node add(Node node, int x) {
        if(node == null){
            return new Node(x);
        }
        if(x < node.val){
            node.left = add(node.left, x);
        }else if(x > node.val){
            node.right = add(node.right, x);
        }else{
            node.nums++;
        }
        return node;
    }
    
    public int getRankOfNumber(int x) {
        return find(root, x);
    }
    private int find(Node node, int x){
        if(node == null)
            return 0;
        int res = 0;
        if(node.val <= x){
            res += node.nums;
            res += find(node.right, x);
        }
        res += find(node.left, x);
        return res;
    }
}

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank obj = new StreamRank();
 * obj.track(x);
 * int param_2 = obj.getRankOfNumber(x);
 */
```
