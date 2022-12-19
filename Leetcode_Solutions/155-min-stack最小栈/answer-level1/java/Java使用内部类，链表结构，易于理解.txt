class MinStack {
    Node node;

    /** initialize your data structure here. */
    public MinStack() {

    }
    
    public void push(int x) {
        if(node==null){
            node=new Node(x,x);
        }else{
            node=new Node(x,node,Math.min(x,node.min));
        }
    }
    
    public void pop() {
        
        node=node.next;
        
    }
    
    public int top() {
        
        return node.val;
        
    }
    
    public int getMin() {
        return node.min;
    }
    private class Node{
        int val;
        Node next;
        int min;
        Node(int val,int min){
            this.val=val;
            this.min=min;
        }
        Node(int val,Node next,int min){
            this.val=val;
            this.next=next;
            this.min=min;
        }
    }
}