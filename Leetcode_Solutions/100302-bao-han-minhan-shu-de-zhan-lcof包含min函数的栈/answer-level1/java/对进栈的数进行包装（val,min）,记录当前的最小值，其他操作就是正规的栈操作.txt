改进栈
```
class MinStack {
    private class Node{
        int val;
        int min;
        public Node(int val,int min){
            this.val=val;
            this.min=min;
        }
    }
    Stack<Node>stack=new Stack<Node>();
    /** initialize your data structure here. */
    public MinStack() {
        
    }
    
    public void push(int x) {
        int min;
        if(stack.isEmpty()){
            min=x;
        }else{
            if(x<stack.peek().min){
                min=x;
            }else min=stack.peek().min;
        }
        Node node=new Node(x,min);
        stack.push(node);
    }
    
    public void pop() {
        stack.pop();
    }
    
    public int top() {
        return stack.peek().val;
    }
    
    public int min() {
        return stack.peek().min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */
```
链表法
```
class MinStack {
    private class Node{
        int val;
        int min;
        Node next;
        public Node(int val,int min,Node next){
            this.val=val;
            this.min=min;
            this.next=next;
        }
    }
    public Node head;
    /** initialize your data structure here. */
    public MinStack() {
        
    }
    
    public void push(int x) {
        if(head==null)
            head=new Node(x,x,null);
        else
            head=new Node(x,Math.min(head.min,x),head);
    }
    
    public void pop() {
        head=head.next;
    }
    
    public int top() {
        return head.val;
    }
    
    public int min() {
        return head.min;
    }
}
```


