# 解题思路


用两个队列q1,q2实现，一碰到top/pop操作就把当前使用的队列全扔另一个里面，返回最后扔的那个值，
top,pop的差别只在top操作最后一个值不删除，pop操作最后一个值要删除


# 代码
```
class MyStack {

    LinkedList<Integer> q1,q2;
    int flag=1;
    //flag代表当前有数据的是哪个队列

    /** Initialize your data structure here. */
    public MyStack() {
        q1=new LinkedList<>();
        q2=new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(flag==1)
            q1.addLast(x);//1 2
        else
            q2.addLast(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        int res=-1;

    //每次执行pop()/top()操作，都要进行一次队列交换操作

        if(flag==1)
        {
            while(!q1.isEmpty())
            {
                int tmp=q1.removeFirst();
                if(q1.size()==0)
                    res=tmp;
                else
                    q2.add(tmp);
            }
            
        }
        else
        {

            while(!q2.isEmpty())
            {
                int tmp=q2.removeFirst();
                if(q2.size()==0)
                    res=tmp;
                else
                    q1.add(tmp);
            }

        }



        flag=(flag==1?2:1);
        return res;
    }
    
    /** Get the top element. */
    public int top() {

        int res=-1;
        if(flag==1)
        {
            while(!q1.isEmpty())
            {
                int tmp=q1.removeFirst();
                if(q1.size()==0)
                    res=tmp;
                q2.add(tmp);
            }
            
        }
        else
        {

            while(!q2.isEmpty())
            {
                int tmp=q2.removeFirst();
                if(q2.size()==0)
                    res=tmp;
                q1.add(tmp);
            }

        }



        flag=(flag==1?2:1);
        return res;

    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        if(q1.isEmpty() && q2.isEmpty())
            return true;
        else
            return false;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
```
