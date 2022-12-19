### 解题思路
插入前进行出队入队操作
``` Java
class MyStack {


    Queue2 q1 ;
    Queue2 q2 ;


    /** Initialize your data structure here. */
    public MyStack() {
        q1 = new Queue2();
        q2 = new Queue2();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
    	while(!q1.isEmpty()) {
    		q2.push(q1.pop());
    	}
    	q1.push(x);
    	while(!q2.isEmpty()) {
    		q1.push(q2.pop());
    	}
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return q1.pop();
    }
    
    /** Get the top element. */
    public int top() {
        return q1.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q1.isEmpty();
    }
    
    public static void main(String[] args) {
    	MyStack obj = new MyStack();
	   	 obj.push(1);
	   	 obj.push(2);
	   	 int param_2 = obj.pop();
	   	 int param_3 = obj.top();
	   	 boolean param_4 = obj.empty();
	}
}

class Queue2 {
    
    private Node head;
    private Node tail;

    private int count = 0;

    public Queue2(){

    }

    public int size(){
        return count;
    }

    public void push(int x){
        Node cur = new Node(x);
        cur.prev = tail;
        if(tail!=null)
            tail.next = cur;
        if(head == null){
            head = cur;
        }
        tail = cur; 

        count ++;
    }

    public int pop(){
        Node n = head;
        head = head.next;
        if(head!=null)
        	head.prev = null;
        n.prev = null;
        n.next = null;
        count --;
        if(count ==0)
        	tail = null;
        return n.x;
    }

    public int peek(){
        return head.x;
    }

    public boolean isEmpty(){
        return count == 0;
    }

}

class Node{
    int x;
    Node next;
    Node prev;

    public Node(int x){
        this.x = x;
        next = null;
        prev = null;
    }
}
```

