![题解1.png](https://pic.leetcode-cn.com/a65f4cbe2c299edf5f02a93fdd44114cede5eb6e1fca8605169a6ab074f8de23-%E9%A2%98%E8%A7%A31.png)
![题解2.png](https://pic.leetcode-cn.com/e9876cca59e071b1ef921e0868255359379f618166f9e047e116bc3a799b8bb5-%E9%A2%98%E8%A7%A32.png)

```
class MinStack {

    public Node top;
    /**
     * initialize your data structure here.
     */
    public MinStack() {
        top=null;
    }

    public void push(int x) {
        //头插法
        Node node=new Node(x);
        if(top==null){
            node.min=x;
        }else {
            node.min=Math.min(top.min,x);
        }
        node.next=top;
        top=node;
    }

    public void pop() {
        if(top!=null) {
            top = top.next;
        }
    }

    public int top() {
        return top.val;
    }

    public int min() {
        return top.min;
    }

    class Node{
        int val;
        int min;
        Node next;
        public Node(int val){
            this.val=val;
        }
    }
}
```
