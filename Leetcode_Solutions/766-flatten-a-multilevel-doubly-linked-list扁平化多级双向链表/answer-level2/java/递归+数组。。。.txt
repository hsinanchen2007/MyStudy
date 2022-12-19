执行速度打败了100% 用了数组arraylist存next然后拼接回去- -半递归。。。
如果有能优化我这个的麻烦教我一下。。。orz总觉得应该不用数组存next。。。


class Solution {
    public Node flatten(Node head) {
        
        if(head == null){
            return head;
        }
        
        Node f = head;
        Node n = head;
        
        ArrayList<Node> temp = new ArrayList();
        
        while(n.next != null || n.child != null){
            
            if(n.child != null){
                
                if(n.next != null){
                    temp.add(n.next);
                }
                
                f = n;
                n = n.child;
                f.next = n;
                n.prev = f;
                f.child = null;
            }
            else if(n.next != null){
                f = n;
                n = n.next;
            }    
        }    
        for(int i = temp.size() - 1; i >= 0; i--){
            f = n;
            Node h = flatten(temp.get(i));
            n = h;
            f.next = n;
            n.prev = f;
            f.child = null;
            while(n.next != null){
                f = n;
                n = n.next;
            }
        }
        
        return head;
        
    }
}