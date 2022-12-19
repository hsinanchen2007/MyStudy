```java
import javafx.util.Pair;
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
         List<String> results = new ArrayList();
        if(root == null){
            return results;
        }
       
        LinkedList<Pair<TreeNode, String>> queue = new LinkedList();
        queue.add(new Pair(root, ""+root.val));
        while(!queue.isEmpty()){
           Pair<TreeNode,String> p =  queue.pollLast();
           TreeNode n = p.getKey();
           String path = p.getValue();
           if(n.right != null){
               queue.add(new Pair(n.right,path + "->" + n.right.val));
           }
           if(n.left != null){
                queue.add(new Pair(n.left,path + "->"+ n.left.val));
           }
           if(n.left == null && n.right == null){
               results.add(path);
           }
        }
        return results;
    }
}
```