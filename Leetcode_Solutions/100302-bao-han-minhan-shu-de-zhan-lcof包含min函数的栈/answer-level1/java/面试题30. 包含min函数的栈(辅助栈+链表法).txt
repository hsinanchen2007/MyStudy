### 解题思路
利用辅助栈，如果压入的x小于辅助栈的栈顶元素或者辅助栈为空， 直接add(x)；否则将辅助栈栈顶元素再次入栈，这样的好处就是出栈的时候不需要进行逻辑判断，只需要数据栈辅助栈都出栈一个元素就行了。

### 代码

```java
class MinStack {
    Stack<Integer> A,B;
    public MinStack() {
        A=new Stack<>();
        B=new Stack<>();
    }
    
    public void push(int x) {
        A.add(x);
        if(B.empty())B.add(x);
        else if(x<=B.peek()){
            B.add(x);
        }else B.add(B.peek());
    }
    
    public void pop() {
        if(A!=null&&B!=null){
           A.pop();
           B.pop(); 
        }
    }
    
    public int top() {
        return A.peek();
    }
    
    public int min() {
        return B.peek();
    }
}
```
### 链表法
```
class MinStack {
    Node head;
    public MinStack() {
    } 
    public void push(int x) {
        if(head==null)head=new Node(x,x,null);
        else head=new Node(x,Math.min(x,head.min),head);//头插法，头的min永远最小
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
}
```
