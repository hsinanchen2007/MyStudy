

```
//迭代法，用栈
import java.util.LinkedList;
import java.util.Deque;
class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> res=new LinkedList<Integer>();
        if(root==null)return res;
        Deque<Node> stack=new LinkedList<Node>();
        stack.push(root);
        res.add(root.val);
        while(!stack.isEmpty()){
            Node p=stack.peek();
            if(p.children.size()==0){
                stack.pop();
            }
            else{
                res.add(p.children.get(0).val);
                stack.push(p.children.get(0));
                p.children.remove(0);

            }
        }
        return res;


        
    }
}
```
```
//递归
class Solution {
    List<Integer> res=new LinkedList<Integer>();
    public List<Integer> preorder(Node root) {         
          if(root==null)return res;
          res.add(root.val);
          for(int i=0;i<root.children.size();i++){
              preorder(root.children.get(i));
          }
          return res;      
    }
    
}
```

