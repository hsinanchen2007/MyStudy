### 解题思路
自定义一个类MyList双向链表，同时维护MyList类型的头head和尾tail，这样可以做到push,pop,top等操作，那么怎么进行O(1)操作的取最小值呢？
方法很简单，每一个MyList中定义一个min，表示到目前该节点为止，当前栈中的最小值。这样，取最小值操作只需要返回tail.prev.min，而每次push(x)只需多出一个操作，那就是存放Math.min(x,tail.prev.min)的值。
### 代码

```java
class MinStack {

    final class MyList{
        int val;
        int min;
        MyList next;
        MyList prev;
        public MyList(int val,int min)
        {
            this.val=val;
            this.min=min;
        }
    } 
    private MyList head,tail;
    /** initialize your data structure here. */
    public MinStack() {
        head=new MyList(-1,Integer.MAX_VALUE);
        tail=new MyList(-1,0);
        head.next=tail;
        tail.prev=head;
    }
    
    public void push(int x) {
        MyList prev=tail.prev;
        MyList node=new MyList(x,Math.min(prev.min,x));
        
        //连接
        prev.next=node;
        node.prev=prev;

        node.next=tail;
        tail.prev=node;
    }
    
    public void pop() {
        MyList top=tail.prev;
        if(top==head)return;

        MyList prev=top.prev;
        prev.next=tail;
        tail.prev=prev;
        top=null;
    }
    
    public int top() {
        return tail.prev.val;
    }
    
    public int getMin() {
        return tail.prev.min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```