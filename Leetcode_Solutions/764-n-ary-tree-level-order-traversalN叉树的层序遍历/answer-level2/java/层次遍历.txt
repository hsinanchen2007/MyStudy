```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> rlist = new LinkedList<>();
        if(root == null) return rlist;
        
        List<Node> slist = new LinkedList<>();
        slist.add(root);
        while(!slist.isEmpty()){
            List<Integer> tlist = new LinkedList<>();
            int size = slist.size();
            for(int i=0;i<size;i++){
               Node curNode = slist.remove(0);
               List<Node> nodeChildren = curNode.children;
               int childrenNum = nodeChildren.size();

               tlist.add(curNode.val);
               for(int j = 0;j < childrenNum; j++){
                   Node child = nodeChildren.get(j);
                   if(child != null){
                      slist.add(child); 
                   }
               }
            }
            
        rlist.add(tlist);
        }
        
        return rlist;
    }
}```