使用两个队列，一个存储当前层的节点，另一个存储下一层的节点。思路和二叉树的层序遍历一致。
```
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        //当前层节点
        Queue<Node> now=new LinkedList();
        now.add(root);
        List<List<Integer>> order=new ArrayList<List<Integer>>();
        //下一层节点
        Queue<Node> next=new LinkedList();
        Node p=null;
        List<Integer> num=new ArrayList();
        while(now.size()>0||next.size()>0||p!=null){
            p=now.poll();
            
            if(p!=null) {
                num.add(p.val);
                for(Node q:p.children){
                next.add(q);
            }
            }
            
            if(now.size()==0){
                if(num.size()>0)
                  order.add(num);
                now=next;
                next=new LinkedList<Node>();
                num=new ArrayList<Integer>();
            }
        }
        return order;
    }
}
```
